#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

int n;
struct que
{
    int a, b, c;
};

vector<que> arr;
int dp[100100][4];

int rec(int level, int choice)
{
    if (level >= n)
        return 0;
    if (dp[level][choice] != -1)
        return dp[level][choice];
    int ans = 0;
    int temp = choice;
    if (choice != 1)
    {
        choice = 1;
        ans = max(ans, arr[level].a + rec(level + 1, choice));
        choice = temp;
    }
    if (choice != 2)
    {
        choice = 2;
        ans = max(ans, arr[level].b + rec(level + 1, choice));
        choice = temp;
    }
    if (choice != 3)
    {
        choice = 3;
        ans = max(ans, arr[level].c + rec(level + 1, choice));
        choice = temp;
    }
    return dp[level][choice] = ans;
}

void solve()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << "\n";
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