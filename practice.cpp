#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define vi vector <int>
using ll = long long;
using ii = pair<int,int>;
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

vector<vector<ii>>g;
int dist[505][505];

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    g.resize(n+1);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <=n ;j++){
            if(i == j)dist[i][j] = 0;
            else dist[i][j] = 1e9;
        }
    }
    for(int i = 0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }
    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while(q--){
        int x, y; cin >> x >> y;
        if(dist[x][y] >= 1e9)cout << "-1\n";
        else cout << dist[x][y] << "\n";
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