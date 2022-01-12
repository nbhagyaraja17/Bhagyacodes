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
// find 4 different indices such that their sum is equal to tar(given).
// O(n^2 logn)
void solve()
{
    int n, tar; cin >> n >> tar;
    vector<int>arr(n);
    for(auto &i : arr)cin >> i;
    map<int,pair<int,int>>mp;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int x = arr[i] + arr[j];
            mp[x] = {i,j};
        }
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++){
            int y = arr[i] + arr[j];
            if(mp.find(tar-y) != mp.end() && mp[tar-y].first != i && mp[tar-y].second != i && mp[tar-y].first != j && mp[tar-y].second != j){
                cout << "YES: " << mp[tar-y].first << " " << mp[tar-y].second << " " << i << " " << j << "\n";
                return;
            }
        }
    }
    cout << "NO\n";
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