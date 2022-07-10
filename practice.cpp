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
int dist[100100];
vector<vector<int>>g;

void bfs(int st){
    for(int i = 0; i<=n; i++)dist[i] = 1e9;
    dist[st] = 0;
    queue<int>q;
    q.push(st);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto v : g[cur])
        {
            if(dist[cur] + 1 < dist[v])
            {
                dist[v] = dist[cur] + 1;
                q.push(v);
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    g.resize(n+1);
    for(int i = 0; i<m; i++){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
    }
    int st, en; cin >> st >> en;
    bfs(st);
    cout << dist[en] << "\n";
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