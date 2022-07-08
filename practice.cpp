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

// find if there is any cycle in directed graph, print any cycle elements
vector<vector<int>>g;
vector<int>col;
vector<int>parent;
bool is_cycle =0;
vector<int>any_cycle;

void dfs(int node, int par)
{
    col[node] = 2;
    parent[node] = par;
    for(auto v : g[node])
    {
        if(col[v] == 1)
        {
            dfs(v, node);
        }
        else if(col[v] == 2)
        {
            if(is_cycle == 0)
            {
                int temp = node;
                while(temp != v){
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }
                any_cycle.push_back(temp);
                reverse(any_cycle.begin(), any_cycle.end());
            }
            is_cycle = 1;
        }
    }
    col[node] = 3;
}
void solve()
{
    int n, m; cin >> n >> m;
    g.resize(n+1);
    for(int i = 0; i<m; i++)
    {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }
    col.assign(n+1, 1);
    parent.assign(n+1, 0);
    any_cycle.clear();
    for(int i = 1; i<=n ;i++)
    {
        if(col[i] == 1)
        {
            dfs(i, 0);
        }
    }
    for(auto i : any_cycle)cout << i << " "; cout << "\n";
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