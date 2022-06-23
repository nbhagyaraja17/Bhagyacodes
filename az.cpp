#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

vector<int>edges[150005];
bool visited[150005];
int n, m;
void solve()
{
    cin >> n >> m;
    for(int i = 0; i<m; i++)
    {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    bool ok = true;
    for(int i = 1; i<=n; i++)
    {
        if(!visited[i]){
            queue<int>q;
            q.push(i);
            vector<int>component;
            while(!q.empty())
            {
                int front = q.front();
                q.pop();
                visited[front] = 1;
                component.push_back(front);
                for(auto ii : edges[front])
                {
                    if(!visited[ii])
                    {
                        q.push(ii);
                        visited[ii] = 1;
                    }
                }
            }
            for(auto x : component)
            {
                if(edges[x].size() != component.size() - 1)
                {
                    cout << "NO\n";
                    return;
                }
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