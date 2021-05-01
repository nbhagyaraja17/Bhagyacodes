#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using ll = long long;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;

template <class T>
void print_data(T &a)
{
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}
ll power(ll x, ll y)
{
    ll temp;
    ll ans = 1;
    while (y)
    {
        if (y & 1)
        {
            ans = (1LL * ans * x) % mod;
        }
        x = (1LL * x * x) % mod;
        y /= 2;
    }
    return ans;
}

string s;
ll cnt, a, b, num, len;

// 1 2  3   4
// 1 1  2   2
// 1 11 111 1111
bool check_prime() // O(sqrt(n))
{
    string temp = s;
    string dup;
    if (s.length() >= 1)
    {
        if (len % 2)
        {
            dup = s.substr(0, s.length() - 1);
            reverse(dup.begin(), dup.end());
        }
        else
        {
            dup = s;
            reverse(dup.begin(), dup.end());
        }
        temp += dup;
        num = stoll(temp);
        //cout << "debg : " << num << "\n";
        if (num < 2)
            return false;
        if (num == 2 && (a <= num) && (num <= b))
            return true;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
                return false;
        }
        return (true && (a <= num) && (num <= b));
    }
}

// 1 0 0 1 1 0 0 1
//
void brute(int level, int n)
{
    if (num > b)
        return;
    if (level == n)
    {
        if (check_prime())
        {
            cnt++;
        }
        return;
    }
    for (int choice = 0; choice <= 9; choice++)
    {
        if (s.empty() && choice == 0)
            continue;
        s.push_back(choice + '0');
        brute(level + 1, n);
        s.pop_back();
    }
}

void solve() // O(5*5!*sqrt(n)*c)
{
    cin >> a >> b;
    ll temp1 = a;
    ll temp2 = b;
    int len1(0), len2(0);
    while (temp1)
    {
        len1++;
        temp1 /= 10;
    }
    while (temp2)
    {
        len2++;
        temp2 /= 10;
    }
    //
    for (int i = len1; i <= len2; i++)
    {
        len = i;
        ll hlen = (i + 1) / 2;
        brute(0, hlen);
    }
    //cout << "ans is: ";
    cout << cnt << "\n";
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