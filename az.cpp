#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;


// Ques : binary array given. u can replace k elements with opposite values. 
// what is the longest subarray with only 1's u can make.
void solve()
{
    int n, k; cin >> n >> k;
    vector<int>a(n);
    for(int i = 0; i<n; i++)cin >> a[i];
    int head = -1;
    int tail = 0;
    int ans = 0;
    int cntzero = 0;
    while(tail < n){
        // updating head (push head as far as possible)
        while((head + 1 < n) && (a[head+1] == 1 || (a[head + 1] == 0 && cntzero < k))){
            head++;
            if(a[head] == 0)cntzero++;
        }
        // updating ans
        ans = max(ans, head - tail + 1); // empty subarray it gives 0.
        // updating tail
        if(head < tail){ // that means empty subarray 
            tail++;
            head = tail -1; // if it is empty subarray , then we want to once again maintain empty subarray.
        }
        else{
            if(a[tail] == 0)cntzero--;
            tail++;
        }
    }
    cout << ans <<"\n";
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