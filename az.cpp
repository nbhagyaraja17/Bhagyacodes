#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

vector<int> arr(505);
int n;
int dp[505][505];

// here the profit we get for merging is benifit and the profit is (a%100)*(b%100);
int rec(int l, int r) // returns max benifit from [l to r]
{
    if (l == r) // for single element we don't need to merge so the benifit is 0.
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    int ans(0), sum(0), tot(0);
    for (int i = l; i <= r; i++)
        tot += arr[i];
    for (int mid = l; mid < r; mid++)
    {
        sum += arr[mid];
        ans = max(ans, rec(l, mid) + rec(mid + 1, r) + (sum % 100) * ((tot - sum) % 100));
    }
    return dp[l][r] = ans;
}

void solve()
{
    cin >> n;
    arr.resize(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << rec(0, n - 1);
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