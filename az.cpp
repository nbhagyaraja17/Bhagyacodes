#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;

const int mod = 1e9 + 7;

int n;
ll sum, ans;

// my approach generate possible subsets and if s == sum/4, ans++, then prune it off and then do it 
// 4 for 4 square sides if my ans is not 4 then NO.
void brute(vector<ll> a)
{
    ll s;
    for (int k = 0; k < 4; k++) //3*N*2^N + N ==> 1.5*1e6 approx.
    {
        if (k < 3)
            for (ll i = 1; i < (1LL << (ll)a.size()); i++)
            {
                s = 0;
                vector<int> del;
                for (ll j = 0; j < (ll)a.size(); j++)
                {
                    if ((i & (1LL << j)) && a[j])
                    {
                        s += a[j];
                        del.push_back(j);
                    }
                }
                if (s == sum / 4)
                {
                    ans++;
                    for (auto x : del)
                    {
                        a[x] = 0;
                    }
                }
            }
        else
        {
            s = 0;
            for (int j = 0; j < (int)a.size(); j++)
            {
                s += a[j];
            }
            if (s == sum / 4)
                ans++;
        }
    }
}
void solve()
{
    cin >> n;
    vector<ll> a(n);
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 4 != 0)
    {
        cout << "NO\n";
        return;
    }
    brute(a);
    cout << (ans == 4 ? "YES\n" : "NO\n");
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