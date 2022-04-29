#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

// 0 1 knapsack problem in top down approach
// given item wt, item value, bag weight capacity
// find max value
void solve()
{
    int n, W; cin >> n >> W;
    vector<int>wt(n),value(n);
	for(auto &i : value)cin >> i;
    for(auto &i : wt)cin >> i;
    // int W; cin >> W;
    // int dp[n+1][W+1];
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<n+1; j++){
            if(i == 0 || j == 0)dp[i][j] = 0;
        }
    }
    for(int i = 1; i<n+1; i++)
    {
        for(int j = 1; j<W+1; j++)
        {
            if(wt[i-1] <= j){
                dp[i][j] = max(value[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i = 0; i<n+1; i++){
        for(int j =0; j<W; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << dp[n][W] << "\n";
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