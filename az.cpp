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

// abcd
// a + rec(bcd)--> b + rec(cd)--> c + rec(d) cd dc 
//                 c + rec(bd)--> b + rec(d) bd db
//                 d + rec(bc)--> b + rec(c) bc cb
// b + rec(acd)
// 
// 
// c + rec(bad)
// 
// 
// d + rec(bca)
// 
// 
int n;
int c;
set<string>st;
void rec(int level, string s)
{
    if(level == s.size())
    {
        cout << s << "\n";
        return;
    }
    for(int i = level; i<s.size(); i++)
    {
        swap(s[level], s[i]);
        rec(level+1, s);
        swap(s[level], s[i]);
    }
}
void solve()
{
    string s; cin >> s;
    n = s.length();
    rec(0, s);
    // cout << c << "\n";
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