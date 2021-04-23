#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

int n, ans;
vector<int> queens;
template <class T>
void print_data(T &a)
{
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}

bool check(int row, int col)
{
    for (int prow = 0; prow < row; prow++)
    {
        int pcol = queens[prow];
        if ((pcol == col) || (abs(prow - row) == abs(pcol - col)))
            return 0;
    }
    return 1;
}

void brute(int row)
{
    //print_data(queens);
    if (row == n)
    {
        ans++;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (check(row, col))
        {
            queens.push_back(col);
            brute(row + 1);
            queens.pop_back();
        }
    }
}

void solve()
{
    cin >> n;
    brute(0);
    cout << ans << "\n";
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