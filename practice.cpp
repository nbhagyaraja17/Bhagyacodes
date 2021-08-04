#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;
int nn;
int dp[1001][10001];
vector<pair<int,int>>vnew;
int rec(int level, int cur)
{
    if(level > nn || cur < 0)return INT_MIN;
    if(level == nn)return 0;
    if(dp[level][cur]!=-1)return dp[level][cur];
    int ans = max(rec(level+1,cur), vnew[level].first + rec(level + 1, cur- vnew[level].second));
    return dp[level][cur] = ans;
}
signed main()
{
    cin >> n;
    vector<pair<int,int>>v(n);
    for(int i = 0; i<n; i++)cin >> v[i].first >> v[i].second;
    int Q;
    cin >> Q;
    vector<int>mark(n+1);
    unordered_map<int,vector<int>>ump;
    int c = 1;
    while(Q--){
        int x, y; cin >> x >> y;
        if(mark[x-1] == 0 && mark[y-1] == 0)
        {
            mark[x-1] = c; mark[y-1] = c;
            ump[c].push_back(x-1); ump[c].push_back(y-1);
        }
        else if(mark[x-1] == 0 && mark[y-1]!=0){
            mark[x-1] = mark[y-1]; ump[mark[y-1]].push_back(x-1);
        }
        else if(mark[x-1]!=0 && mark[y-1] == 0){
            ump[mark[x-1]].push_back(y-1);
            mark[y-1] = mark[x-1];
        }
        else{
            auto it = ump.find(mark[y-1]);
            for(auto val: it->second)ump[mark[x-1]].push_back(val);
            ump.erase(it);
            mark[y-1] = mark[x-1];
        }
        c++;
    }
    for(int i = 0; i<n; i++)if(mark[i] == 0)vnew.push_back({v[i].first, v[i].second});
    for(auto it = ump.begin(); it!= ump.end(); it++){
        int sk = 0; int wg = 0;
        for(auto val : it->second)sk+=v[val].first, wg+=v[val].second;
        vnew.push_back({sk,wg});
    }
    //for(auto val : vnew)cout << val.first << " " << val.second << "\n";
    int B; cin >> B;
    nn = (int)vnew.size();
    memset(dp,-1,sizeof(dp));
    cout << rec(0,B) << "\n";
    return 0;
}