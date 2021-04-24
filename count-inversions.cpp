// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long left, long long mid , long long right, long long arr[]) {
        long long i = left, j = mid + 1;
        long long temp[right - left +1];
        long long counter = 0, inversions = 0;

        while (i <= mid && j <= right)
        {
            if (arr[i] <= arr[j]) {
                temp[counter++] = arr[i++];
            } else {
                temp[counter++] = arr[j++];
                inversions += (mid - i + 1);
            }
        }

        while (i <= mid) temp[counter++] = arr[i++];

        while (j <= right) temp[counter++] = arr[j++];

        for (int i = 0, j = left; j <= right; i++, j++) arr[j] = temp[i];

        return inversions;
    }

    long long mergesort(long long arr[], long long left, long long right) {
        if (left >= right) return 0;

        long long inversions = 0;
        long long mid = left +  (right - left) / 2;
        inversions += mergesort(arr, left, mid);
        inversions += mergesort(arr, mid + 1, right);
        inversions += merge(left, mid, right, arr);
        return inversions;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        return mergesort(arr, 0, N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends