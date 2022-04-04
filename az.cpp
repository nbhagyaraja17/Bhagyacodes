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

// max area(rect) histogram problem
void solve()
{
    int n; cin >> n;
    vector<int>arr(n);
    for(auto &i : arr)cin >> i;
    stack<int>temp;
    vector<int>left(n),right(n);
    for(int i  = 0; i<n; i++){
        while(!temp.empty() && arr[temp.top()] >= arr[i])temp.pop();
        if(temp.empty())left[i] = i+1;
        else left[i] = i - temp.top();
        temp.push(i);
    }
    while(!temp.empty())temp.pop();
    for(int i  = n-1; i>=0; i--){
        while(!temp.empty() && arr[temp.top()] >= arr[i])temp.pop();
        if(temp.empty())right[i] = n-i;
        else right[i] = temp.top() - i;
        temp.push(i);
    }
    // for(auto i : left)cout << i << " ";
    // cout << "\n";
    // for(auto i : right)cout << i << " ";
    // cout << "\n";
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans = max(ans, (left[i]+right[i]-1)*arr[i]);
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