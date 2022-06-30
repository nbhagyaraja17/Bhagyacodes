#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define vi vector <int>
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

int cnt[100100];
int distinct;
void add(int x)
{
    if(cnt[x] == 0)distinct++;
    cnt[x]++;
}
void remove(int x)
{
    cnt[x]--;
    if(cnt[x] == 0)distinct--;
}
void solve()
{
    int n, k; cin >> n >> k;
    vi arr(n);
    for(auto &i : arr)cin >> i;
    int tail = 0;
    int head = -1;
    int ans = 0;
    while(tail < n)
    {
        while(head + 1 < n && ((distinct < k) or ( (distinct == k) and (cnt[arr[head + 1]] > 0) )))
        {
            head++;
            add(arr[head]);
        }
        ans = max(ans, head - tail + 1);
        if(head < tail)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            remove(arr[tail]);
            tail++;
        }
    }
    cout << ans << "\n";
}

signed main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}