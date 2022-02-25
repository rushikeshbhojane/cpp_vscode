// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        long long sumForward[n];
        long long current = 0;
        
        for (int i = 0; i < n; i++) {
            current += a[i];
            sumForward[i] = current;
        }
        
        long long totalSum = sumForward[n-1];
        
        for (int i = 0; i < n; i++)  {
            long long sumBefore, sumAfter = totalSum - sumForward[i];
            if (i == 0) sumBefore = 0;
            else sumBefore = sumForward[i-1];
            
            if (sumBefore == sumAfter)  return a[i];
        }
        
        return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends