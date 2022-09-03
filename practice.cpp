#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// #define int long long
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

#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

// Declaring Ordered Set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
    long long n, k; cin >> n >> k;
    pbds ost;
    for(int i = 1; i<=n; i++)
    {
        ost.insert(i);
    }
    long long i = k % n;
    while(!ost.empty())
    {
        cout << *(ost.find_by_order(i % (int)ost.size())) << " ";
        ost.erase(*ost.find_by_order(i % (int)ost.size()));
        // deb(i);
        // n--;
        if((int)ost.size()) i = (i + k) % (int)ost.size();
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