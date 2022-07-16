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
// dijkstra algorithm

using ii = pair<int,int>;
#define F first
#define S second
int n, m;
vector<ii>g[100100];
vector<int>dist, vis;

void dijkstra(int sc)
{
    priority_queue<ii>pq;
    dist[sc] = 0;
    pq.push({-0, sc});
    while(!pq.empty())
    {
        ii fs = pq.top(); pq.pop();
        if(vis[fs.S])continue;
        vis[fs.S] = 1;
        for(auto v : g[fs.S])
        {
            int neigh = v.F;
            int weigh = v.S;
            if(dist[neigh] > dist[fs.S] + weigh)
            {
                dist[neigh] = dist[fs.S] + weigh;
                pq.push({-dist[neigh], neigh});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    dist.assign(n+1, 1e18);
    vis.assign(n+1, 0);
    for(int i = 0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dijkstra(1);
    int tar; cin >> tar;
    cout << dist[tar] << "\n";
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