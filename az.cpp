#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

int n;

// O(nlogn) 
int lis(vector<int> v)
{
    vector<int> temp;
    for (auto x : v)
    {
        if (temp.empty() || temp.back() < x)
            temp.push_back(x);
        else
        {
            auto it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }
    return temp.size(); // here we are just getting the longest subsequence length not the solution.
}

void solve()
{
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << lis(arr);
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