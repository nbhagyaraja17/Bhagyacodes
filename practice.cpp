#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define vi vector <int>
using ll = long long;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

// problem : given n segments with l, r, and priority value called x
// q queries given, for every y value print the highest priority value, if there is no segment at that value print -1
void solve()
{
    int n, q; cin >> n >> q;
    vector<pair<int,int>>events;
    for(int i = 0; i<n; i++)
    {
        int l, r, x; cin >> l >> r >> x;
        events.push_back({l, x});
        events.push_back({r, -x});
    }
    sort(all(events));
    mulitset<int>mst;
    map<pair<int,int>, int>vals;
    for(int i = 0; i<events.size(); i++)
    {
        if(events[i].second < 0)
        {
            mst.erase(mst.find(-events[i].second));
        }
        else
        {
            mst.insert(events[i].second);
        }
        if(!mst.empty())
        {
            auto it = mst.end(); it--;
            if(i + 1 < events.size())vals[{events[i].first , events[i+1].first}] = *it;
        }
    }
    while(q--)
    {
        int y; cin >> y;
        auto it = vals.lower_bound({y,0});
        if(it != vals.begin())
        {
            it--;
            if((it->first).second >= y)
                cout << it->second << "\n";
            else cout << "-1\n";
        }
        else cout << "-1\n";
    }
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