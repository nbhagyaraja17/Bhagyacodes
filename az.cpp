#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

// balanced paranthesis of depth k and size n
// T.C  


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

int n, ans, cnt, k;
string s;
vector<string> sol;

void brute(int level)
{
    // print_data(s);
    if (cnt < 0 || (n - level < cnt))
        return;
    if (level == n)
    {
        if (cnt == 0)
        {
            int depth = 0, max_dep = 0;
            for (int i = 0; i < s.length(); i++) // finding depth
            {
                if (s[i] == '(')
                    depth++;
                else
                    depth--;
                max_dep = max(max_dep, depth);
                if (depth > k)
                    return;
            }
            if (max_dep == k) // comparing depth
                sol.push_back(s);
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
    cin >> n >> k;
    brute(0);
    sort(sol.begin(), sol.end());
    for (auto it : sol)
    {
        cout << it << "\n";
    }
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