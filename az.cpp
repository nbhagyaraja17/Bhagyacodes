#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

int n, cnt;
vector<int> arr;
int dp[3030][3030];

// from that level how can you combine the level to n-1 elements addup to remsum.
// from level 0 to level n-1 how many ways can you add the elements to make remsum that is n intially.
// intial values are 0, n
int rec(int level, int remsum)
{
    if (remsum < 0)
        return 0;
    if (level == n)
    {
        return remsum == 0;
    }
    if (dp[level][remsum] != -1)
        return dp[level][remsum];
    int ans = rec(level, remsum - arr[level]) + rec(level + 1, remsum);
    return dp[level][remsum] = ans;
}
void solve()
{
    cin >> n;
    arr.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n);
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