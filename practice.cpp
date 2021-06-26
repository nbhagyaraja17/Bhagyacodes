#include <bits/stdc++.h>
using namespace std;

int SuperFrequentElement(vector<int> &v)
{
    // Complete the function
    // boyer moores voting algorithm
    int count = 0;
    int ans = v[0];
    for(int i = 0 ; i<v.size(); i++){
        if(count == 0)ans = v[i];
        if(ans == v[i])count++;
        else count--;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    cout << SuperFrequentElement(v) << "\n";
}