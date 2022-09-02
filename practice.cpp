#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define vi vector <int>
using ll = long long;
using ii = pair<int,int>;
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

vector<int>prefix_function(string &s){
    int n = (int)s.size();
    vector<int>pi(n);
    for(int i = 1; i<n; i++)
    {
        int j = pi[i-1];
        while(j > 0 && (s[i] != s[j]))
        {
            j = pi[j-1];
        }
        if(s[i] == s[j])
        {
            pi[i] = j + 1;
        }
    }
    return pi;
}

void solve()
{
    string s; cin >> s;
    vector<int>pi = prefix_function(s);
    for(auto i : pi)cout << i << " ";
    cout << "\n";
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