// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    int getPairsCount(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int count = 0;
        int left = 0, right = n-1;
        
        while (left < right) {
            if (arr[left] + arr[right] == k) {
                int leftIndex = left, rightIndex = right;
                while(left < right && arr[left] == arr[leftIndex]) left++;
                while(right >= left && arr[right] == arr[rightIndex]) right--;
                
                if (arr[leftIndex] == arr[rightIndex]) {
                    int totalCount = (left - leftIndex) + (rightIndex - right);
                    count += (totalCount*(totalCount - 1))/2;
                } else {
                    count += ((left - leftIndex) * (rightIndex - right));
                }
            }
            else if (arr[left] + arr[right] < k) left++;
            else right--;
        }
        
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends