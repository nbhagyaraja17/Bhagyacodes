#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

int arr[100100];
int t[400400];
int n;
void update(int id, int l, int r, int lu, int ru, int v)
{
    if (r < lu || ru < l)
        return;
    if (lu <= l && ru >= r) // mist1
    {
        t[id] += v;
        //cout << "update tid " << id << " " << t[id] << endl;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, lu, ru, v);
    update(2 * id + 1, mid + 1, r, lu, ru, v);
}
int query(int id, int l, int r, int x)
{
    int sum = 0;
    if (r < x || l > x)
        return 0;
    if (l == x && r == x)
        return t[id];
    if (l <= x && x <= r) // mist3 
    {
        sum = t[id];
    }
    int mid = (l + r) / 2;
    return sum + query(2 * id, l, mid, x) + query(2 * id + 1, mid + 1, r, x); // mist2
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            update(1, 0, n - 1, l, r, v);
        }
        else
        {
            int x;
            cin >> x;
            cout << query(1, 0, n - 1, x) + arr[x] << endl;
        }
    }
}

int main()
{
    //fast;
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}