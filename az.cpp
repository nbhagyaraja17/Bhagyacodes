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

// stack 01
// next greater element to the right 
void solve()
{
    int n; cin >> n;
    vector<int>arr(n);
    for(auto &i : arr)cin >> i;
    stack<int>st;
    vector<int>ans(n);
    for(int i = n-1; i>=0; i--)
    {
        while(!st.empty() && st.top() <= arr[i])st.pop();
        if(st.empty())ans[i] = -1;
        else ans[i] = st.top();
        st.push(arr[i]);
    }
    for(auto i : ans)cout << i << " ";
    cout << "\n";
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