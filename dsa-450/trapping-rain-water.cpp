// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
// { Driver Code Starts
#include<iostream>

using namespace std;


 // } Driver Code Ends


class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        int totalWaterTrapped = 0;
        int left[n], right[n], maxLeft, maxRight;
        left[0] = maxLeft = arr[0];
        right[n-1] = maxRight = arr[n-1];
        
        for (int i = 1; i < n; i++) {
            maxLeft = max(maxLeft, arr[i]);
            left[i] = maxLeft;
        }
        
        
        for (int i = n-2; i >= 0; i--) {
            maxRight = max(maxRight, arr[i]);
            right[i] = maxRight;
        }
        
        for (int i = 0; i < n; i++) {
            int minPossible = min(left[i], right[i]);
            if (minPossible - arr[i] > 0) {
                totalWaterTrapped += (minPossible - arr[i]);
            }
        }

        return totalWaterTrapped;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends