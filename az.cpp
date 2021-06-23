#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

struct node
{
    int lsum, rsum, msum, tsum;
    node(int l = 0, int r = 0, int m = 0, int t = 0)
    {
        lsum = l;
        rsum = r;
        msum = m;
        tsum = t;
    }
};

int n;
node tr[1001];
vector<int> arr;

node merge(node a, node b)
{
    int m = max(a.msum, max(a.rsum + b.lsum, b.msum));
    int l = max(a.lsum, a.tsum + b.lsum);
    int r = max(b.rsum, b.tsum + a.rsum);
    int t = a.tsum + b.tsum;
    return node(l, r, m, t);
}

void build(int i, int l, int r)
{
    if (l == r)
    {
        tr[i] = node(arr[l], arr[l], arr[l], arr[l]);
        return;
    }
    ll m = (l + r) / 2;
    build(2 * i, l, m);
    build(2 * i + 1, m + 1, r);
    tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
}

void update(int i, int l, int r, int x, int v)
{
    if (l > x || r < x)
        return;
    if (l == x && r == x)
    {
        tr[i] = node(v, v, v, v);
        return;
    }
    ll m = (l + r) / 2;
    update(2 * i, l, m, x, v);
    update(2 * i + 1, m + 1, r, x, v);
    tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
}

node query(int i, int l, int r, int lef, int rig)
{
    if (rig < l || lef > r)
    {
        return node(-1e9, -1e9, -1e9, -1e9);
    }
    if (lef <= l && r <= rig)
        return tr[i];
    ll m = (l + r) / 2;
    return merge(query(2 * i, l, m, lef, rig), query(2 * i + 1, m + 1, r, lef, rig));
}

void solve()
{
    int q;
    cin >> n >> q;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int pos, v;
            cin >> pos >> v;
            pos--;
            update(1, 0, n - 1, pos, v);
        }
        else
        {
            int lef, rig;
            cin >> lef >> rig;
            lef--;
            rig--;
            cout << query(1, 0, n - 1, lef, rig).msum << "\n";
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