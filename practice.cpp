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

// find union length and intersection length of n segments
void solve()
{
    int n; cin >> n;
    vector<pair<int,int>>events;
    int L_max = 0, R_min = INT_MAX;
    for(int i = 0; i<n; i++)
    {
        int l, r; cin >> l >> r;
        L_max = max(L_max, l); R_min = min(R_min, r);
        events.push_back({l,1});
        events.push_back({r, -1});
    }
    int cnt = 0;
    int union_len = 0;
    for(int i = 0; i<(int)events.size(); i++)
    {
        cnt += events[i].second;
        if(cnt > 0 && i + 1 < (int)events.size())
         // if we want union of >= k segments then replacing cnt >= k
        {
            union_len += (events[i+1].first - events[i].first);
        }
    }
    int intersection_len = max(0LL, R_min - L_max);
    cout << union_len << " " << intersection_len << "\n";
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