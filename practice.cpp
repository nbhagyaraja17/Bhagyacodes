#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

vector<int>arr;
int n, k;
int F(int t)
{
    long long sumtemp = 0;
    long long cnt = 0;
    for(int i = 0; i<n; i++){
        sumtemp += arr[i];
        if(sumtemp > t){
            sumtemp = 0;
            i--;
            cnt++;
        }
    }
    return cnt<=k;
}

void solve()
{
    cin >> n >> k;
    arr.resize(n);
    ll sum = 0;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int lo =  *max_element(arr.begin(),arr.end());
    int hi = sum;
    long long ans = 0;
    while(lo < hi){
        int mid = lo + (hi - lo)/2;
        if(F(mid)){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid + 1;
        }
    }
    while()
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