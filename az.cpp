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

int n, m, q;
vector<vector<int>>g;
bool visited[100100];
vector<int>id,sz;
int cur_ID = 0;
void dfs(int node)
{
    visited[node] = 1;
    id[node] = cur_ID;
    sz[cur_ID]++;
    for(auto v : g[node])
    {
        if(!visited[v])dfs(v);
    }
}
void solve()
{
    cin >> n >> m >> q;
    g.resize(n+1);
    id.assign(n+1,-1);
    sz.assign(n+1,0);
    for(int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 1; i<=n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            cur_ID++;
        }
    }
    while(q--)
    {
        int t; cin >> t;
        if(t == 1)
        {
            int x; cin >> x;
            cout << sz[id[x]] << "\n";
        }
        else
        {
            int x, y; cin >> x >> y;
            if(id[x] == id[y])cout << "YES\n";
            else cout << "NO\n";
        }
    }
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