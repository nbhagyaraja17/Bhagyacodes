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

// finding topological ordering using dfs and bfs (Kahn's algo) in DAG
int n, m;
vector<vector<int>>g;
vector<bool>visited;
vector<int>topo1,topo2;

void dfs(int node)
{
    visited[node] = 1;
    for(auto v : g[node]){
        if(!visited[v])dfs(v);
    }
    topo1.push_back(node);
}

vector<int>indeg;

void kahns(){
    queue<int>q;
    for(int i = 1; i<=n; i++){
        if(indeg[i] == 0)q.push(i);
    }
    while(!q.empty()){
        int cur = q.front(); 
        q.pop();
        topo2.push_back(cur);
        for(auto v : g[cur]){
            indeg[v]--;
            if(indeg[v] == 0)q.push(v);
        }
    }
}
void solve()
{
    cin >> n >> m;
    g.resize(n+1);
    visited.assign(n+1,0);
    indeg.assign(n+1,0);
    for(int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        indeg[y]++;
    }
    for(int i = 1; i<=n; i++){
        if(!visited[i])dfs(i);
    }
    kahns();
    reverse(all(topo1));
    for(auto v : topo1)cout << v << " "; cout << "\n";
    for(auto v : topo2)cout << v << " "; cout << "\n";
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