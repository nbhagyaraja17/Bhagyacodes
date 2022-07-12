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
vector<int>col,parent;
vector<int>any_cycle;
bool cycle = 0;
void dfs(int node, int par)
{
    col[node] = 2;
    for(auto v : g[node])
    {
        if(v == par)continue;
        if(col[v] == 1)
        {
            parent[v] = node;
            dfs(v, node);
        }
        else if(col[v] == 2)
        {
            // storing cycle
            // if(!cycle)
            // {
            //     int temp = node;
            //     while(temp != v){
            //         any_cycle.push_back(temp);
            //         temp = parent[temp];
            //     }
            //     any_cycle.push_back(temp);
            //     reverse(all(any_cycle));
            // }
            cycle = 1;
        }
    }
    col[node] = 3;
}
void solve()
{
    cin >> n >> m;
    col.assign(n+1,1);
    parent.assign(n+1,-1);
    g.resize(n+1);
    for(int i = 0; i<m; i++)
    {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // cout << "hi\n";
    for(int i = 1; i<=n ; i++)
    {
        if(col[i] == 1)dfs(i, -1);
    }
    cout << (cycle ? "YES\n" : "NO\n");
    // printing cycle
    // for(auto i : any_cycle)cout << i << " "; cout << "\n";
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