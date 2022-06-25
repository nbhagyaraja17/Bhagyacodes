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

bool nextPermutation(string &nums) 
{
    if(nums.empty()) return false;
    int i=nums.size()-1;
    while(i>=1 && nums[i]<=nums[i-1]) i--;
    if(i==0) return false; // no next permutation, i.e. already largest
    
    int j=nums.size()-1;
    while(nums[j]<=nums[i-1]) j--;
    swap(nums[i-1],nums[j]);
    
    reverse(nums.begin()+i,nums.end());
    return true;
}
void solve()
{
    string s; cin >> s;
    if(nextPermutation(s))cout << s << "\n";
    else cout << "-1\n";
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