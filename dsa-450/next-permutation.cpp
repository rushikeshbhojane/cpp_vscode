// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int current  = N - 1;
        bool flag = false;
        
        while (current > 0)
        {
            if (arr[current-1] < arr[current])
            {
                sort(arr.begin()+current, arr.end());
                swap(arr[current-1], *upper_bound(arr.begin()+current, arr.end(), arr[current-1]));
                break;
            } else {
                current--;
            }
        }

        if (current == 0) {
            sort(arr.begin(), arr.end());
        }
        
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends