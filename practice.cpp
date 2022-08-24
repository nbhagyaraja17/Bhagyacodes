#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define vi vector <int>
using ll = long long;
using ii = pair<int,int>;
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

int n, m;
int hotel_rooms[200002];
int req_rooms[200002];
int tr[800008];

// finding index which is greater than given x in given l, r:
// query format: x, l, r
// output format: printing index, if not found then print -1

void build(int i, int l , int r){
    if(l == r){
        tr[i] = hotel_rooms[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*i, l, mid);
    build(2*i + 1, mid + 1, r);
    tr[i] = max(tr[2*i], tr[2*i + 1]);
}

void update(int i, int l, int r, int x, int val){
    if(x < l or x > r)return;
    if(l == x and r == x){
        tr[i] -= val;
        return;
    }
    int mid = (l + r)/2;
    update(2*i, l, mid, x, val);
    update(2*i + 1, mid + 1, r, x,  val);
    tr[i] = max(tr[2*i], tr[2*i + 1]);
}

int query(int i, int l, int r, int lq, int rq, int v)
{
    if(r < lq or rq > l)return -1;
    if(lq <= l and r <= rq)
    {
        if(tr[i] <= v)return -1;
        while(l < r)
        {
            int mid = (l + r)/2;
            if(tr[2*i] > v)
            {
                i = 2*i;
                r = mid;
            }
            else
            {
                i = 2*i + 1;
                l = mid + 1;
            }
        }
        return l;
    }
    int mid = (l + r)/2;
    int ls = query(2*i, l, mid, lq, rq, v);
    if(ls != -1)return ls;
    return query(2*i + 1, mid + 1, r, lq, rq, v);
}

void solve()
{
    cin >> n >> m;
    for(int i = 0; i<n; i++)cin >> hotel_rooms[i];
    for(int i = 0; i<m; i++)cin >> req_rooms[i];
    build(1, 0, n-1);
    for(int i = 0; i<m; i++){
        int ans = query(1, 0, n-1, req_rooms[i]);
        if(ans != -1)
        {
            update(1, 0, n-1, ans, req_rooms[i]);
        }
        cout << ans + 1 << " ";
    }
    cout << "\n";
}

signed main()
{
    fast;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}