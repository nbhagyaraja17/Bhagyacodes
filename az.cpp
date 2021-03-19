#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;

const int mod = 1e9 + 7;

ll n, ans, cnt;
string s;

void solve()
{
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    do
    {
        for (auto i : a)
            cout << i << " ";
        cout << "\n";
    } while (next_permutation(a.begin(), a.end()));
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