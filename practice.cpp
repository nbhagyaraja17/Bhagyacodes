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
int n, m;
vector<vector<ii>>g;
vector<int>dist;
vector<bool>vis;

void dijkstra(int sc){
    dist[sc] = 0;
    priority_queue<ii>pq;
    pq.push({-0, sc});
    while(!pq.empty())
    {
        ii fr = pq.top(); pq.pop();
        int neigh = fr.S;
        int weigh = -fr.F;
        if(vis[neigh])continue;
        vis[neigh] = 1;
        for(auto v : g[neigh])
        {
            if(dist[v.F] > dist[neigh] + v.S)
            {
                dist[v.F] = dist[neigh] + v.S;
                pq.push({-dist[v.F], v.F});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    g.resize(n+1);
    dist.assign(n+1, 1e9);
    vis.assign(n+1, false);
    for(int i = 0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b,c});
    }
    dijkstra(1);
    for(int i = 1; i<=n; i++)cout << dist[i] << " ";
    cout << "\n";
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