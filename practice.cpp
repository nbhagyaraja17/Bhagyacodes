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

// *** WITHOUT REPETITION***
// find is it possible to have four indices a, b, c, d (without repetition allowed) 
// such that arr[a] + arr[b] + arr[c] + arr[d] == target

// idea : A + B + C + D == target.. splitting A + B to X and C + D to Y
// getting all the possible A + B i.e, X and mapping them and then checking if any tar - Y presents in our map
// if presents then that will be our X 


bool is4sumPossible(vector<int>arr, int n, int tar){
    map<int,int>mp;
    for(int b = n-3; b>=1; b--){
        for(int a = b-1; a>=0; a--)
        {
            mp[arr[a] + arr[b]] = 1;
        }
        int c = b+1; 
        for(int d = c+1; d<n; d++){
            if(mp[tar-(arr[c] + arr[d])]){
                return 1;
            }
        }
    }
    return 0;
}
void solve()
{
    int n, tar; cin >> n >> tar;
    vector<int>arr(n);
    for(auto &i: arr)cin >> i;
    cout << is4sumPossible(arr, n, tar) << "\n";
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