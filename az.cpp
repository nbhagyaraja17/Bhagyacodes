#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

string s;
int dp1[1010][1010];

// form 4 dp
int rec1(int l, int r) // returns 1 if the substring from l to r is palindrome.
{
    if (l >= r)
        return 1;
    if (dp1[l][r] != -1)
        return dp1[l][r];
    int ans = 0;
    if (rec1(l + 1, r - 1) && s[l] == s[r])
        ans = 1;
    return dp1[l][r] = ans;
}

int dp2[1010];

// TC is O(n^2)
int rec2(int i) // no. of min cuts from 0 to l
{
    if (i == -1)
        return -1;
    int ans = 1e9;
    if (dp2[i] != -1)
        return dp2[i];
    for (int ch = 0; ch <= i; ch++)
    {
        if (rec1(ch, i)) // this is O(1) for only one time it tooks 
            ans = min(ans, rec2(ch - 1) + 1);
    }
    return dp2[i] = ans;
}

void solve()
{
    cin >> s;
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    cout << rec2((int)s.length() - 1);
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