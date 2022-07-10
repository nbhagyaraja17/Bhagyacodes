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
ii dist[1010][1010]; // {distance from st to that cell, no. of ways it got here}
ii par[1010][1010];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// if diagonals are inculded
// int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
// int dy[] = {1, 0, -1, -1, -1, 0,  1, 1};

// if it is chess knight
// int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
// int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};

bool inside(int x, int y)
{
    if(x < 0 or x >= n or y < 0 or y >= m or arr[x][y] == '#')return 0;
    return 1;
}
void bfs(ii st){
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++)dist[i][j] = {1e9, 0};
    }
    dist[st.F][st.S] = {0,1};
    queue<ii>q;
    q.push(st);
    while(!q.empty())
    {
        ii cur = q.front();
        q.pop();
        int curd = dist[cur.F][cur.S].F;
        for(int k = 0; k<4; k++)
        {
            ii neigh = {cur.F + dx[k], cur.S + dy[k]};
            if(!inside(cur.F + dx[k], cur.S + dy[k]))continue;
            if(dist[neigh.F][neigh.S].F > curd + 1)
            {
                dist[neigh.F][neigh.S] = {curd + 1, dist[cur.F][cur.S].S};
                par[neigh.F][neigh.S] = cur; // storing parent for finding path
                q.push(neigh);
            }
            else if(dist[neigh.F][neigh.S].F == curd + 1){
                dist[neigh.F][neigh.S].S += dist[cur.F][cur.S].S;
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
    cout << dist[en.F][en.S].F << " " << dist[en.F][en.S].S << "\n";

    // Finding path from end to start
    // ii temp = en;
    // vector<ii>path;
    // while(temp != st)
    // {
    //     path.push_back(temp);
    //     temp = par[temp.F][temp.S];
    // }
    // path.push_back(temp);
    // reverse(all(path));
    // for(auto i : path)cout << i.F << " " << i.S << "\n";
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