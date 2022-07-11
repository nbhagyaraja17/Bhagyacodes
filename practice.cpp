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
using ii = pair<int,int>;
#define F first
#define S second


int grid[1010][1010];
bool visited[1010][1010];
int n, m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool inside(int x, int y)
{
    if(x < 0 or x >= n or y < 0 or y >= m or grid[x][y] == 0 or visited[x][y] == 1)return 0;
    return 1;
}
void dfs(int i, int j)
{
    visited[i][j] = 1;
    for(int k = 0; k<4; k++)
    {
        ii neigh = {i+dx[k], j+dy[k]};
        if(!inside(neigh.F, neigh.S))continue;
        dfs(neigh.F, neigh.S);
    }
}
void solve()
{
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            visited[i][j] = 0;
            grid[i][j] = 0;
        }
    }
    for(int i = 0; i<n; i++)
    {
        string s; cin >> s;
        for(int j = 0; j<m; j++)
        {
            if(s[j] == '.')grid[i][j] = 1;
        }
    }
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(inside(i,j))
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
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