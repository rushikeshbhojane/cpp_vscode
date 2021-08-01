// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends


int minSwap(int *arr, int n, int k) {
    // Complet the function
    int windowSize = 0;
    int currentSwaps[n];

    int minSwapsRequired = 0, totalSwapsRequired = 0;

    for (int i  = 0; i < n; i++) {
        if (arr[i] <= k) windowSize++;
    }

    for (int i  = 0; i < windowSize; i++) {
        if (arr[i] > k) totalSwapsRequired++;
    }
    minSwapsRequired = totalSwapsRequired;
    
    for (int i = windowSize; i < n; i++) {
        if (arr[i- windowSize] > k) totalSwapsRequired--;
        if (arr[i] > k) totalSwapsRequired++;
        minSwapsRequired = min(minSwapsRequired, totalSwapsRequired);
    }
    
    return minSwapsRequired;
}