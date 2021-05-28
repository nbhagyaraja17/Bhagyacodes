#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

int n;

// given : string
// print no. of distinct subsequences of that string.

// O(n) O(n)
void solve()
{
    string s;
    cin >> s;
    n = (int)s.length();
    int last[30];
    memset(last, -1, sizeof(last));
    int dp[n + 1]; // no. of distinct subsequence ending with that index.
    int sum[n + 1];
    dp[0] = 1; // empty is also a subsequence.
    sum[0] = 1;
    for (int i = 1; i <= n; i++) // level 1 (1 indexing)
    {
        dp[i] = sum[i - 1];
        if (last[s[i - 1] - 'a'] > 0)
            dp[i] -= dp[last[s[i - 1] - 'a']];
        last[s[i - 1] - 'a'] = i;
        sum[i] = sum[i - 1] + dp[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += dp[i];
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}