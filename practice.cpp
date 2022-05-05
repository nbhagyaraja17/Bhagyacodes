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

// if we split an array into 2 subsets completely.
// what is the min sum diff
void solve()
{
    int n; cin >> n;
    vector<int>arr(n);
    for(auto &i : arr)cin >> i;
    int sum = accumulate(arr.begin(), arr.end(),0);
    bool dp[n+1][sum+1];
    for(int j = 0; j<sum+1; j++)dp[0][j] = false;
    for(int i = 1; i<n+1; i++)dp[i][0] = true;
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<sum+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans = INT_MAX;
    for(int j=sum; j>=0; j--)
    {
        if(dp[n][j])
            ans = min(ans, abs(sum-2*j));
    }
    cout << ans << "\n";
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