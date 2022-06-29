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

void solve()
{
    int n, tar; cin >> n >> tar;
    vector<int>arr(n);
    for(auto &i : arr)cin >> i;
    map<int, set<int> >mp;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++)
        {
            mp[arr[i] + arr[j]].insert(i);
            mp[arr[i] + arr[j]].insert(j);
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int cur = tar - (arr[i] + arr[j]);
            if(mp.find(cur) != mp.end())
            {
                if(mp[cur].find(j) == mp[cur].end() && mp[cur].find(i) == mp[cur].end())
                {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

signed main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}