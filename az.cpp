#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

// form 0-1

/*int n, b, k; 
vector<int> p;
vector<int> h;
int dp[1010][1010];
int back[1010][1010];

int rec(int level, int wleft)
{
    if (wleft < 0)
        return INT_MIN;
    if (level == n)
    {
        return 0;
    }
    if (dp[level][wleft] != -1)
        return dp[level][wleft];
    int ans = rec(level + 1, wleft);
    int ans1 = h[level] + rec(level + 1, wleft - p[level]);
    if (ans > ans1)
    {
        back[level][wleft] = 0;
    }
    else if (ans1 > ans)
    {
        ans = ans1;
        back[level][wleft] = 1;
    }
    else
    {
        back[level][wleft] = 2;
    }
    return dp[level][wleft] = ans;
}

vector<vector<int>> allsol;
vector<int> temp;

void getsol(int level, int pricepaid)
{
    if (back[level][pricepaid] == -1)
    {
        allsol.push_back(temp);
        return;
    }
    else if (back[level][pricepaid] == 0)
    {
        getsol(level + 1, pricepaid);
    }
    else if (back[level][pricepaid] == 1)
    {
        temp.push_back(level);
        getsol(level + 1, pricepaid - p[level]);
        temp.pop_back();
    }
    else
    {
        getsol(level + 1, pricepaid);
        temp.push_back(level);
        getsol(level + 1, pricepaid - p[level]);
        temp.pop_back();
    }
}*/

// form 2 ending level max sum in subarray.

/*int n;
vector<int> arr;
int dp[100100];
int done[100100];

int rec(int level)
{
    if (level < 0)
        return 0;
    if (done[level] != -1)
        return dp[level];
    int ans = max(arr[level], arr[level] + rec(level - 1));
    done[level] = 1;
    return dp[level] = ans;
}
/*vector<vector<int>> allsol;
vector<int> temp;
void getsol(int level)
{
    if (back[level] == -1)
    {
        allsol.push_back(temp);
        return;
    }
    else if (back[level] == 0)
    {
        getsol(level + 1);
    }
    else if (back[level] == 1)
    {
        temp.push_back(level);
        getsol(level + 1);
        temp.pop_back();
    }
    else
    {
        getsol(level - 1);
        temp.push_back(level);
        getsol(level + 1);
        temp.pop_back();
    }
}*/

// form 3 LCS longest common subsequence
int n1, n2;
string s1, s2;
int dp[1010][1010];

int rec(int level1, int level2)
{
    if (level1 >= n1 || level2 >= n2)
        return 0;
    if (dp[level1][level2] != -1)
        return dp[level1][level2];
    int ans = max(rec(level1 + 1, level2), rec(level1, level2 + 1));
    if (s1[level1] == s2[level2])
    {
        ans = max(ans, rec(level1 + 1, level2 + 1) + 1);
    }
    return dp[level1][level2] = ans;
}
void solve()
{
    cin >> n1 >> n2;
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0);
    // for (auto v : allsol)
    // {
    //     for (auto x : v)
    //         cout << x << " ";
    //     cout << "\n";
    // }
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