// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
    public:
   //Complete this function
    bool subArrayExists(int arr[], int n)
    {
            int dp[n][n];
        
            for(int i = 0; i < n; i++) {
                dp[i][i] = arr[i];
                if (arr[i] == 0 ) return true;
            }
        
            for(int i = 1; i < n; i++)
            {
                for (int j =  0; j+i < n; j++)
                {
                    dp[j][j+i] = dp[j][j+i-1] + arr[j+i];
                    if (dp[j][j+i] == 0) return true;
                }
            }

            return false;
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}  // } Driver Code Ends