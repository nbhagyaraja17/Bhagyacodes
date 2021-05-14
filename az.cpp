#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

int n;
vector<int> arr;
int dp[100100];

int rec(int level)
{
    if (level < 0)
        return 0;
    if (dp[level] != -1)
        return dp[level];
    int ans = 1;
    for (int i = 0; i < level; i++)
    {
        if (arr[i] < arr[level])
        {
            ans = max(ans, rec(i) + 1);
        }
    }
    return dp[level] = ans;
}

void solve()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    rec(n - 1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}

int main()
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