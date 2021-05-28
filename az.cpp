#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

int dp[101][101];
int X, Y;

// two players are playing stones picking game. 
// either you can take few stones from X, or from Y , or you have to take same no. of stones from X and Y at a time.

// O(N^3) O(N^2)
int rec(int x, int y)// whether 1st player can win that x and y values or not.
{
    if (x == 0 && y == 0)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    int win = 0;
    for (int i = 1; i <= X; i++)
    {
        if (rec(x - i, y) == 0)
            win = 1;
    }
    for (int i = 1; i <= Y; i++)
    {
        if (rec(x, y - i) == 0)
            win = 1;
    }
    for (int i = 1; i <= min(X, Y); i++)
    {
        if (rec(x - i, y - i) == 0)
            win = 1;
    }
    return dp[x][y] = win;
}
void solve()
{
    cin >> X >> Y;
    memset(dp, -1, sizeof(dp));
    cout << rec(X, Y) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}