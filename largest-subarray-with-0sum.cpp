// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

int maxLen(int A[], int n)
{
    // Your code here
    int lenofLargestSubarray = 0;
    map<int, int> sumAndIndex;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += A[i];
        if (sum == 0) {
            lenofLargestSubarray =  max(lenofLargestSubarray, i);
        }
        else if (sumAndIndex.find(sum) == sumAndIndex.end()) {
            sumAndIndex[sum] = i;
        } else {
            lenofLargestSubarray =  max(lenofLargestSubarray, i - sumAndIndex[sum]);
        }
    }
    
    return lenofLargestSubarray;
}