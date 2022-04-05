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

// given : binary matrix
// Cal : max area of histogram containing 1s.
vector<int>left_smaller_index(vector<int>arr){
    int n = (int)arr.size();
    vector<int>ans(n);
    stack<int>temp;
    for(int i = 0; i<n; i++){
        while(!temp.empty() && arr[temp.top()] >= arr[i])temp.pop();
        if(temp.empty())ans[i] = -1;
        else ans[i] = temp.top();
        temp.push(i);
    }
    return ans;
}
vector<int>right_smaller_index(vector<int>arr){
    int n = (int)arr.size();
    vector<int>ans(n);
    stack<int>temp;
    for(int i = n-1; i>= 0; i--){
        while(!temp.empty() && arr[temp.top()] >= arr[i])temp.pop();
        if(temp.empty())ans[i] = n;
        else ans[i] = temp.top();
        temp.push(i);
    }
    return ans;
}
void solve()
{
    int m, n; cin >> m >> n;
    vector<vector<int>>mat(m, vector<int>(n)), cal(m, vector<int>(n, 0));
    for(auto &v : mat){
        for(auto &i : v)cin >> i;
    }
    for(int j = 0; j<n; j++){
        for(int i = 0 ;i<m; i++)
        {
            if(mat[i][j] == 0)continue;
            if(i == 0)
            {
                cal[i][j] = max(cal[i][j], mat[i][j]);
                continue;
            }
            cal[i][j] = max(cal[i-1][j], mat[i-1][j]) + 1;
        }
    }
    // for(auto v : cal){
    //     for(auto i : v)cout << i << " ";
    //     cout << "\n";
    // }
    int ans = 0;
    for(int i = 0; i<m; i++){
        vector<int>temp;
        for(int j = 0; j<n; j++)
        {
            temp.push_back(cal[i][j]);
        }
        vector<int>lns = left_smaller_index(temp);
        vector<int>rns = right_smaller_index(temp);
        for(int i = 0 ;i<n; i++){
            // deb2(rns[i], lns[i]);
            ans = max(ans, (rns[i]-lns[i]-1)*temp[i]);
        }
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