#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;
int tt=1;
vector<string>pos;
vector<int>a;
string temp;
int num;
int len;
void brute(int level){
    if(level > len)return;
    if(level == len-1){pos.push_back(temp);return;}
    for(int i = 0; i<(int)a.size(); i++){
        char c = a[i] + '0';
        temp.push_back(c);
        brute(level+1);
        temp.pop_back();
    }
}
int count(int a, int b){
    int len1 = 0;
    int len2 = 0;
    while(a){
        len1++;
        a/=10;
    }
    while(b){
        len2++;
        b/=10;
    }
    return len1+len2;
}
void solve()
{
    int arr[10];
    for(int i = 0; i<10; i++)
    {
        cin >> arr[i];
        if(arr[i])a.push_back(i);
    }
    cin >> num;
    for(int i = 2; i<=7; i++){
        len = i;
        brute(0);
    }
    //for(auto s: pos)cout << s << " ";
    set<int>st;
    for(auto s: pos)
    {
        int n = stoll(s);
        if(n > num)break;
        else st.insert(n);
    }
    int ans = 1e8;
    for(auto it = st.begin(); it!=st.end(); it++){
        if(num%(*it) == 0 && st.find(num/(*it))!=st.end())ans = min(ans, count(*it, *st.find(num/(*it))));
    }
    cout <<"Case #" << tt << ": ";
    if(ans!=1e8)cout << ans+2<<"\n";
    else cout << "Impossible\n";
    tt++;
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