#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
long long int merge(long long int arr[], int l, int m, int r) {
    int i = l, j = m, k = 0;
    long long int temp[r-l+1], inv_count = 0;
    for (;(i <= m - 1) && (j <= r);) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (m - i);
        }
    }
    while (i <= m - 1)
    {
            temp[k++] = arr[i++];
    }
    
    
    while (j <= r)
    {
            temp[k++] = arr[j++];
    }

    int a = l;
    for (int ele: temp)
    {
        /* code */
        arr[a++] = ele;
    }
    return inv_count;
}
long long int mergeSort (long long int arr[], int l, int r) {
    long long int inv_count = 0;
    if (l < r) {
        int m = l + (r-l)/2;
        inv_count +=  mergeSort(arr, l, m);
        inv_count +=  mergeSort(arr, m+1, r);
        inv_count += merge(arr, l, m+1, r);
    }
    return inv_count;
}
int main() {
    // your code goes here
    int t;
    cin >> t;
    while(t--)  {
        int n;
        cin >> n;
        long long int v[n];
        for (int i = 0; i < n; i++)
        {
            /* code */
            cin >> v[i];
        }
        long long int inversionCount = 0;
        inversionCount =  mergeSort(v, 0, n-1);
        cout << inversionCount << "\n";
    }
    return 0;
}
