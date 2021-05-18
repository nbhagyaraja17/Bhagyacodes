#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

// you have been given two arrays and you have to find the longest possible subsequence length

vector<int> A;
int n, m;

// overall the code is O(nlogn)
int lis(vector<int> &v)
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
    cin >> n >> m;
    map<int, int> mp;
    A.resize(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
    {
        int d;
        cin >> d;
        mp[d] = i; // we assume elements in B as unique that's why we mapped.
    }
    // with the help of mapping now the B sets becomes like 0 1 2 3 4 ... m-1
    // now accoring to those mapped values we also change values in A.
    // now the longest increasing subsequence will be longest common subsequence
    vector<int> temp;
    // O(nlogn)
    for (auto x : A)
    {
        if (mp.find(x) != mp.end())
        {
            temp.push_back(mp[x]);
        }
    }
    // now we have to find the longest increasing subsequence in temp.
    cout << lis(temp);
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