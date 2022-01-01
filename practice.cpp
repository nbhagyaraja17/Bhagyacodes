#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

// ques: given an array. Find no. of subsets whose sum is <= x (including empty subset)
const int mod = 1e9 + 7;
int n, x;
vector<int> arr;
vector<int> gen(vector<int> a)
{
    vector<int> b;
    for (int i = 0; i < (1 << a.size()); i++)
    {
        int sum = 0;
        for (int j = 0; j < a.size(); j++)
        {
            if ((1 << j) & i)
                sum += a[j];
        }
        b.push_back(sum);
    }
    return b;
}
int answer()
{
    vector<int> newarr[2];
    for (int i = 0; i < n; i++)
    {
        newarr[i & 1].push_back(arr[i]);
    }
    vector<int> sub0, sub1;
    sub0 = gen(newarr[0]);
    sub1 = gen(newarr[1]);
    int cnt = 0;
    for (auto v : sub0)
    {
        cnt += upper_bound(sub1.begin(), sub1.end(), x - v) - sub1.begin();
    }
    return cnt;
}
void solve()
{
    cin >> n >> x;
    arr.resize(n);
    for (auto &i : arr)
        cin >> i;
    cout << answer() << "\n";
}

signed main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}