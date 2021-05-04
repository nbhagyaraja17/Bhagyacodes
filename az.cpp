#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

void solve()
{
    ll x, y;
    cin >> x >> y;
    ll op = 0;
    if (x >= y)
    {
        cout << (x - y) << "\n";
    }
    else
    {
        while (y > x)
        {
            if (y & 1)
                y++;
            else
                y /= 2;
            op++;
        }
        cout << op + (x - y) << "\n";
    }
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