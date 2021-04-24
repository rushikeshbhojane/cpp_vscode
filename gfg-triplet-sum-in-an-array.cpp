// { Driver Code Starts
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    // arr[] : The input Array
    // N : Size of the Array
    // X : Sum which you need to search for 
    //Function to find if there exists a triplet in the 
    //array arr[] which sums up to X.
    bool find3Numbers(int arr[], int N, int X)
    {
        //Your Code Here
        unordered_map<int, unordered_set<int>> NoAndIndexes;
        
        for (int i = 0; i < N; i++) {
            NoAndIndexes[arr[i]].insert(i);
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                int sumToFind = X  - ( arr[i] + arr[j]);
                if (!NoAndIndexes[sumToFind].empty()) {
                    if (NoAndIndexes[sumToFind].find(arr[i]) == NoAndIndexes[sumToFind].end() 
                            && 
                        NoAndIndexes[sumToFind].find(arr[j]) == NoAndIndexes[sumToFind].end()) {
                        return true ;   
                    } else if (
                        (NoAndIndexes[sumToFind].find(arr[i]) != NoAndIndexes[sumToFind].end()
                           && NoAndIndexes[sumToFind] > 1)
                    
                    ) {

                    }
                }
            }
        }
        
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,sum;
		cin>>N>>sum;
		int i,A[N];
		for(i=0;i<N;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, N, sum) << endl;
    }
}
  // } Driver Code Ends