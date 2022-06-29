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

void solve()
{
    int n, k; cin >> n >> k;
    vi arr(n);
    for(auto &i : arr)cin >> i;
    int tail = 0;
    int head = -1; // imp for empty subarray
    int ans = 0;
    int cntzero = 0;
    while(tail < n){
        // push head as far as possible
        while(head + 1 < n && (arr[head + 1] == 1 or (arr[head + 1] == 0 and cntzero < k)))
        {
            head++;
            if(arr[head] == 0)cntzero++;
        }
        // updating ans
        ans = max(ans, (head - tail + 1));
        // move tail one step
        if(head < tail)
        {
            tail++;
            head = tail-1;
        }
        else{
            if(arr[tail] == 0)cntzero--;
            tail++;
        }
    }
    cout << ans << "\n";
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