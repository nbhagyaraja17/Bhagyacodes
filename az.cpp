#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using ll = long long;
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const int mod = 1e9 + 7;


int place_pivot(vector<int> &arr, int st, int en){
    int pivot = arr[en];
    int low = st;
    for(int i = st; i<en; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[low], arr[i]);
            low++;
        }
    }
    swap(arr[low], arr[en]);
    return low;
}
void quicksort(vector<int> &arr, int st, int en)
{
    if(st < en)
    {
        int pivot = place_pivot(arr, st, en);
        quicksort(arr, st, pivot-1);
        quicksort(arr, pivot+1, en);
    }
}

void merge(vector<int>&arr, int lo, int mid, int hi)
{
    int i = 0;
    int j = 0;
    int k = lo;
    vector<int>lrr, rrr;
    for(int i = lo; i<= mid; i++)lrr.push_back(arr[i]);
    for(int j = mid+1; j<= hi; j++)rrr.push_back(arr[j]);
    int n1 = mid - lo + 1, n2 = hi - mid;
    while(i < n1 && j < n2)
    {
        if(lrr[i] <= rrr[j])
        {
            arr[k++] = lrr[i++];
        }
        else arr[k++] = rrr[j++];
    }
    while(i < n1){
        arr[k++] = lrr[i++];
    }
    while(j < n2){
        arr[k++] = rrr[j++];
    }
}
void mergesort(vector<int>&arr,int lo, int hi){
    if(lo < hi)
    {
        int mid = (lo + hi)/2;
        mergesort(arr, lo, mid);
        mergesort(arr, mid+1, hi);
        merge(arr, lo, mid, hi);
    }
}
void solve()
{
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &i : arr)cin >> i;

    // selection sort -- selecting min and placing at front repeting it until all min are placed
    // for(int i = 0; i<n; i++)
    // {
    //     int mini = INT_MAX;
    //     int ind = -1;
    //     for(int j = i; j<n; j++)
    //     {
    //         if(mini > arr[j])
    //         {
    //             mini = arr[j];
    //             ind = j;
    //         }
    //     }
    //     swap(arr[i], arr[ind]);
    // }

    // bubble sort -- repeatedly swaping two adjacent elements if left > right
    // by this process every time we are pushing max to end.
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j < n-i-1; j++){
    //         if(arr[j] > arr[j+1]){
    //             swap(arr[j], arr[j+1]);
    //         }
    //     }
    // }

    // insertion sort 
    // here we are having two segregates one is sorted and another is not sorted
    // we take each element from not sorted group and place it in the correct place in sorted group.. like this 
    // we make total array into sorted array.
    // for(int i = 1; i < n; i++)
    // {
    //     int key = arr[i];
    //     int j = i-1;
    //     while(j >= 0 && arr[j] > key){
    //         arr[j+1] = arr[j];
    //         j--;
    //     }
    //     arr[j+1] = key;
    // }
    
    // quicksort(arr, 0, n-1);
    // always treating last element as pivot and placing that in the sorted order of it's original position and then spliting the 
    // array before pivot and after pivot and doing again this for two subarrays.

    mergesort(arr, 0, n-1);
    for(auto val: arr)cout << val << " ";
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