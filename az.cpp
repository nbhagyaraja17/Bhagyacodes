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
vector<int>comp_size;
bool visited[100100];

void dfs(int node, int &cnt)
{
    visited[node] = 1;
    cnt++;
    for(auto v : g[node])
    {
        if(!visited[v])dfs(v, cnt);
    }
}
void solve()
{
    cin >> n >> m;
    g.resize(n+1);
    for(int i = 0 ;i<m; i++){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 1; i<=n; i++)
    {
        if(!visited[i])
        {
            int cnt = 0;
            dfs(i, cnt);
            comp_size.push_back(cnt);
        }
    }
    if(comp_size.empty()){
        cout << "0\n";
        return;
    }

    // pairwise product sum
    int ans = 0;
    int pre = 0;
    for(int i = 0; i<(int)comp_size.size(); i++)
    {
        ans += pre * comp_size[i];
        pre += comp_size[i];
    }
    cout << ans << "\n";
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