#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

int n, m;
int dp[1010][1010];
vector<vector<char>>arr;
int rec(int x, int y){
    if(x > n || y > m)return INT_MIN;
    if(x == n && y== m)return arr[x][y];
    int ans = 0;
    if(arr[x][y] == '#')return dp[x][y] = INT_MIN;
    else ans = max(arr[x][y]+rec(x+1,y) , arr[x][y]+rec(x,y+1));
    return dp[x][y] = ans;
}
void solve()
{
    cin >> n >> m;
    arr.resize(n+1);
    for(int i = 1; i<=n; i++)arr[i].resize(m+1);
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)cin >> arr[i][j];
    memset(dp,-1,sizeof(dp));
    cout << rec(1,1) << "\n";
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