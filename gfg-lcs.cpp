// { Driver Code Starts
#include <iostream>
#include <algorithm>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    // return the length of the longest subsequene of consecutive integers
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      sort(arr, arr + N);
      int LCS  = 1, current_LCS = 1;
      for (int i = 1; i < N; i++) {
          if (arr[i] == arr[i-1] + 1) {
              ++current_LCS;
              LCS =  max(LCS, current_LCS);
          } else if (arr[i] == arr[i-1]) {
              continue;
          } else {
              current_LCS = 0;
          }
      }
      return LCS;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends