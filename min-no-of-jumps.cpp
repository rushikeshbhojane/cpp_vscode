// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){
    // Your code here
    int jumps[n];
    jumps[0] = 0;

    for(int i = 1; i < n; i++) jumps[i] = -1;

    for (int i = 0; i < n-1; i++)
    {
        if (jumps[i] != -1) {
            for (int j = 1; j <= arr[i] && i+j < n; j++)
            {
                if (jumps[i+j] == -1) {
                    jumps[i+j] = jumps[i] + 1;
                } else {
                    jumps[i+j] = min(jumps[i+j], jumps[i] + 1);
                }
            }
        }
    }
    
    return jumps[n-1];
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}