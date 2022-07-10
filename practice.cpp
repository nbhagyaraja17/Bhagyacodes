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
vector<string>arr;
int dist[1010][1010];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool inside(int x, int y){
    if(x < 0 or x >= n or y < 0 or y >= m or arr[x][y] == '#')return 0;
    return 1;
}
void bfs(ii st){
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++)dist[i][j] = 1001;
    }
    dist[st.F][st.S] = 0;
    queue<ii>q;
    q.push(st);
    while(!q.empty())
    {
        ii cur = q.front();
        q.pop();
        int curd = dist[cur.F][cur.S];
        for(int k = 0; k<4; k++)
        {
            ii neigh = {cur.F + dx[k], cur.S + dy[k]};
            if(!inside(cur.F + dx[k], cur.S + dy[k]))continue;
            if(dist[neigh.F][neigh.S] > curd + 1)
            {
                dist[neigh.F][neigh.S] = curd + 1;
                q.push(neigh);
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    arr.resize(n+1);
    ii st, en;
    for(int i = 0; i<n ;i++){
        cin >> arr[i];
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 'S')st = {i,j};
            else if(arr[i][j] == 'E')en = {i,j};
        }
    }
    bfs(st);
    cout << dist[en.F][en.S] << "\n";
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