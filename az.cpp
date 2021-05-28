#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

// no. of strings such that their length should be n and it should not contain "0100" as substring.

int n;
int dp[100100][4]; // bcoz string length is 4.

// first we have to write automata on notes then we have to proceed.
// That means we have to write the states for that particular string.

int rec(int level, int match)
{
    if (level == n)
        return 1;
    int ans = 0;
    if (dp[level][match] != -1)
        return dp[level][match];
    if (match == 0)
    {
        ans = rec(level + 1, 0) + rec(level + 1, 1);
    }
    else if (match == 1)
    {
        ans = rec(level + 1, 1) + rec(level + 1, 2);
    }
    else if (match == 2)
    {
        ans = rec(level + 1, 0) + rec(level + 1, 3);
    }
    else
    {
        ans = rec(level + 1, 0);
    }
    return dp[level][match] = ans;
}

void solve()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
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