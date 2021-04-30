#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

// segment tree structure
// T.C for updating logn , for sum logn so.. overall O(QlogN)

template <class T>
void print_data(T &a)
{
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}
ll power(ll x, ll y)
{
    ll temp;
    ll ans = 1;
    while (y)
    {
        if (y & 1)
        {
            ans = (1LL * ans * x) % mod;
        }
        x = (1LL * x * x) % mod;
        y /= 2;
    }
    return ans;
}

vector<int> arr(100100);
vector<int> tree(400400);
int n, q;

void build(int index, int l, int r)
{
    if (l == r)
    {
        tree[index] = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    tree[index] = tree[2 * index] + tree[2 * index + 1];
}

void update(int index, int l, int r, int x, int v)
{
    if (x < l || r < x)
        return;
    if (l == r)
    {
        tree[index] = v;
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * index, l, mid, x, v);
    update(2 * index + 1, mid + 1, r, x, v);
    tree[index] = tree[2 * index] + tree[2 * index + 1];
}

ll sum_query(int index, int l, int r, int pleft, int pright)
{
    if (r < pleft || pright < l)
        return 0;
    if (pleft <= l && pright >= r)
        return tree[index];
    int mid = (l + r) / 2;
    return (sum_query(2 * index, l, mid, pleft, pright) + sum_query(2 * index + 1, mid + 1, r, pleft, pright));
}

void solve()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    while (q--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int x, v;
            cin >> x >> v;
            update(1, 0, n - 1, x, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << sum_query(1, 0, n - 1, l, r) << "\n";
        }
    }
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