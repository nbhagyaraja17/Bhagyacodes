#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

int n, ans, cnt;
string s;
template <class T>
void print_data(T &a)
{
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}
ll power(ll x, ll y)
{
    ll temp;
    ll ans = 1;
    while (y)
    {
        if (y & 1)
        {
            ans = (1LL * ans * x) % mod;
        }
        x = (1LL * x * x) % mod;
        y /= 2;
    }
    return ans;
}

void brute(int level)
{
    print_data(s);
    if (cnt < 0 || (n - level < cnt))
        return;
    if (level == n)
    {
        if (cnt == 0)
        {
            cout << s << "\n";
            ans++;
        }
        return;
    }
    // move
    s += '(';
    cnt++;
    brute(level + 1);
    cnt--;
    s.pop_back();
    // move
    s += ')';
    cnt--;
    brute(level + 1);
    cnt++;
    s.pop_back();
}

void solve()
{
    cin >> n;
    brute(0);
    cout << ans << "\n";
}

int main()
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