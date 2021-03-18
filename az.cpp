#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> edges(4, 0);
ll n, sum;

bool solve(vector<ll> &a, ll start)
{
    if (start == n)
    {
        return true;
    }

    for (int i = 0; i < 4; i++)
    {
        if (edges[i] + a[start] <= sum / 4)
        {
            edges[i] += a[start];
            if (solve(a, start + 1))
                return true;
            else
                edges[i] -= a[start];
        }
    }
    return false;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        sum = 0;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % 4)
            cout << "NO" << endl;
        else
        {
            for (int i = 0; i < 4; i++)
            {
                edges[i] = 0;
            }
            cout << (solve(a, 0) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}