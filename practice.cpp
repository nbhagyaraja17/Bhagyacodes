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

int n;
vector<int>arr;
vector<string>ans;
void perm(int level, string s, set<int>present){
    if(level == n){
        ans.push_back(s);
        return;
    }
    for(int i = 0; i<n; i++){
        if(present.empty() || (!present.empty() && present.find(i) == present.end()))
        {
            string before = s;
            s += to_string(arr[i]);
            present.insert(i);
            perm(level+1, s, present);
            present.erase(i);
            s = before;
        }
    }
}
void solve()
{
    cin >> n;
    arr.resize(n);
    for(auto &i : arr)cin >> i;
    set<int>p;
    perm(0, "", p);
    for(auto i : ans){
        cout << i << "\n";
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