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
vector<string>g;
int distmonst[1010][1010];
int distA[1010][1010];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
ii parA[1010][1010];

ii msbfs(){
    queue<ii>monstOcc, Aocc;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            distmonst[i][j] = 1e9;
            distA[i][j] = 1e9;
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(g[i][j] == 'M')
            {
                monstOcc.push({i,j});
                distmonst[i][j] = 0;
            }
            else if(g[i][j] == 'A')
            {
                Aocc.push({i,j});
                distA[i][j] = 0;
                parA[i][j] = {-1,-1};
            }
        }
    }
    while(!monstOcc.empty()){
        ii fr = monstOcc.front(); monstOcc.pop();
        for(int i = 0; i<4; i++)
        {
            ii neigh = {fr.F + dx[i], fr.S + dy[i]};
            if(neigh.F < 0 or neigh.F >= n or neigh.S < 0 or neigh.S >= m or g[neigh.F][neigh.S] == '#')
                continue;
            if(distmonst[neigh.F][neigh.S] > distmonst[fr.F][fr.S] + 1)
            {
                distmonst[neigh.F][neigh.S] = distmonst[fr.F][fr.S] + 1;
                monstOcc.push(neigh);
            }
        }
    }
    while(!Aocc.empty()){
        ii fr = Aocc.front(); Aocc.pop();
        for(int i = 0; i<4; i++)
        {
            ii neigh = {fr.F + dx[i], fr.S + dy[i]};
            if(neigh.F < 0 or neigh.F >= n or neigh.S < 0 or neigh.S >= m or g[neigh.F][neigh.S] == '#')continue;
            if(distA[neigh.F][neigh.S] > distA[fr.F][fr.S] + 1)
            {
                distA[neigh.F][neigh.S] = distA[fr.F][fr.S] + 1;
                Aocc.push(neigh);
                parA[neigh.F][neigh.S] = {fr.F, fr.S};
            }
        }
    }
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++)cout << distA[i][j] << " ";
    //     cout << "\n";
    // }
    ii escp_coord = {-1,-1};
    int escp_dist = 1e9;
    for(int j = 0; j<m; j++){
        if(g[0][j] != '#' and distA[0][j] < distmonst[0][j]){
            escp_coord = {0,j};
            escp_dist = min(escp_dist, distA[0][j]);
        }
        if(g[n-1][j] != '#' and distA[n-1][j] < distmonst[n-1][j]){
            escp_coord = {n-1,j};
            escp_dist = min(escp_dist, distA[n-1][j]);
        }
    }
    for(int i = 0; i<n; i++){
        if(g[i][0] != '#' and distA[i][0] < distmonst[i][0]){
            escp_coord = {i,0};
            escp_dist = min(escp_dist, distA[i][0]);
        }
        if(g[i][m-1] != '#' and distA[i][m-1] < distmonst[i][m-1]){
            escp_coord = {i,m-1};
            escp_dist = min(escp_dist, distA[i][m-1]);
        }
    }
    if(escp_coord.F == -1)cout << "NO\n";
    else{
        cout << "YES\n";
        cout << escp_dist << "\n";
    }

    // printing path
    // string path;
    // int x = escp_coord.F, y = escp_coord.S;
    // while(1){
    //     int prex = parA[x][y].F;
    //     int prey = parA[x][y].S;
    //     if(prex == -1 and prey == -1)break;
    //     if(y - prey == 1)path += 'R';
    //     else if(y - prey == -1)path += 'L';
    //     else if(x - prex == 1)path += 'D';
    //     else path += 'U';
    //     x = prex; y = prey;
    // }
    // reverse(all(path));
    // cout << path << "\n";
    
}
void solve()
{
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i<n; i++)cin >> g[i];
    msbfs();
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