#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

ll n;
string s;

void solve()
{
    cin >> n;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    ll odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[s[i]] % 2)
        {
            odd++;
        }
    }
    if (n % 2 == 0)
    {
        if (odd)
        {
            cout << "-1\n";
            return;
        }
    }
    else
    {
        if (odd > 1)
        {
            cout << "-1\n";
            return;
        }
    }
    ll cnt = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            
        }
        deb(s);
    }
    cout << cnt << "\n";
}

int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}