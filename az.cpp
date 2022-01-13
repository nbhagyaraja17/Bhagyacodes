#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;
int n;
set<set<int>>st;
void generate(int i, int a, int b, int c, int d, vector<int>v)
{
    if(i == v.size())
    {
        st.insert({a,b,c,d});
        return;
    }
    generate(i+1, a+v[i], b, c, d, v);
    generate(i + 1, a, b + v[i], c, d, v);
    generate(i + 1, a, b, c + v[i], d, v);
    generate(i + 1, a, b, c, d + v[i], v);
}
void solve()
{
    cin >> n;
    vector<int>a, b;
    int sum = 0;
    for(int i = 0; i<n; i++){
        int d; cin >> d;
        if(i<n/2)a.push_back(d);
        else b.push_back(d);
        sum += d;
    }
    if(sum % 4 !=  0)
    {
        cout << "NO\n";
        return;
    }
    generate(0, 0, 0, 0, 0, a);
    set<set<int>>posa = st;
    st.clear();
    generate(0, 0, 0, 0, 0, b);
    set<set<int>>posb = st;
    st.clear();
    for(auto it : posa)
    {
        set<int>temp;
        for(auto itt: it)temp.insert(sum/4 - itt);
        if(posb.find(temp) != posb.end())
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main()
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