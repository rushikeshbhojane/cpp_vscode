// { Driver Code Starts
#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
    long long maxProduct(int *arr, int n) {
	    // code here
	    long long max_so_far = 0;
	    long long max_ending_here = 1, min_ending_here = 1;
        bool flag;
	    for (int i = 0; i < n; i++) {

            if (arr[i] > 0) {
                max_ending_here = max_ending_here * arr[i];
                min_ending_here =  min(min_ending_here * arr[i],  1LL);
                flag  = 1;
            }
            else if (arr[i] == 0) {
                max_ending_here = min_ending_here = 1;
            }
            else {
                long long temp = max_ending_here;
                max_ending_here = max(min_ending_here * arr[i], 1LL);
                min_ending_here = temp * arr[i];
            }

            if (max_ending_here > max_so_far) {
                max_so_far = max_ending_here;
            }
	    }
        if (flag == 0 && max_so_far == 0)
            return 0;
	    
	    return max_so_far;
	}
	
	long long maxOf3(long long arg1, long long arg2, long long arg3){
	    long long ret = max(arg1,arg2);
        ret = max(ret, arg3);
        return ret;
	}

	long long minOf3(long long arg1, long long arg2, long long arg3){
	    long long ret = min(arg1,arg2);
        ret = min(ret, arg3);
        return ret;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends