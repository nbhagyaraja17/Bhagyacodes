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

int n, m;
vector<vector<int>>g;
vector<int>col;
bool ok = true;

bool dfs(int node, int c)
{
    for(auto v : g[node])
    {
        if(col[v] == c)return false;
        else if(col[v] == -1)
        {
            col[v] = c^1;
            return dfs(v, col[v]);
        }
    }
    return true;
}

void solve()
{
    cin >> n >> m;
    g.resize(n+1);
    col.assign(n+1,-1);
    for(int i = 0; i<m; i++)
    {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 1; i<=n; i++){
        if(col[i] == -1)
        {
            if(!dfs(i, 0)){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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