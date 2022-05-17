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

int m;
void solve()
{
    string s, t;
    cin >> s >> t;
    int m = s.size();
    int n = t.size();
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
    for(int i = 1; i<m+1; i++){
        for(int j = 1; j<n+1; j++){
            if(s[i-1] == t[j-1])dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[m][n] << "\n";
    int i = m, j = n;
    string ans;
    while(i > 0 && j > 0)
    {
        if(dp[i][j] != max(dp[i-1][j], dp[i][j-1])){
            ans += s[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])i--;
        else j--;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << "\n";
}

signed main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}