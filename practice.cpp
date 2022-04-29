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

// subset sum problem in topdown
void solve()
{
    int n, sum; cin >> n >> sum;
    vector<int>arr(n);
    for(auto &i : arr)cin >> i;
    int dp[n+1][sum+1];
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(j == 0)dp[i][j] = 1;
            else if(i == 0)dp[i][j] = 0;
        }
    }
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<sum+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][sum] << "\n";
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