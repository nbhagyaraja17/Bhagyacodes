#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;

const int mod = 1e9 + 7;

ll n, ans, cnt;
string s;

void brute(ll p)
{
    if (p == n)
    {
        if (cnt == 0)
            cout << s << "\n";
    }
    if (cnt > 0)
    {
        s.push_back(')');
        cnt--;
        brute(p + 1);
    }
    else
    {
        s.push_back('(');
        cnt++;
        brute(p + 1);
    }
}

void solve()
{
    cin >> n;
    brute(0);
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