#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

string s;
int dp1[1010][1010];
int rec1(int l, int r){ // returns 1 if from [l..r] is palindrome and this is zero based index, but
//  we are sending 1 based index values
    if(l >= r)return 1;
    if(dp1[l][r]!=-1)return dp1[l][r];
    int ans = 0;
    if(s[l-1] == s[r-1] && rec1(l+1,r-1)){ // the only change due to zero and one based index confusion.
        ans = 1;
    }
    return dp1[l][r] = ans;
}

int dp[100100];
int rec(int i){// returns no. of min cuts from [1...i]
    if(i == 0)return -1;
    if(dp[i]!=-1)return dp[i];
    int ans = INT_MAX;
    for(int j = i-1; j>=0; j--){
        if(rec1(j+1,i)){
            ans = min(rec(j)+1, ans);
        }
    }
    return dp[i] = ans;
}
void solve()
{
    cin >> s;
    int n = (int)s.length();
    memset(dp,-1,sizeof(dp));
    memset(dp1,-1,sizeof(dp1));
    cout << rec(n) << "\n";
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