// { Driver Code Starts
//Initial template for C++

#include <iostream>
#include <vector>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        int alen = A.size();
        vector<bool> dp(alen+1, false);
        for(int i = 0; i <= alen; i++) {
            if(!dp[i] && find(B.begin(), B.end(), A.substr(0, i)) != B.end()) {
                dp[i] = true;
            }

            if (dp[i]) {
                if (i == alen) {
                    return true;
                }
                for (int j=i+1; j <= alen; j++) {
                    if(!dp[j] && find(B.begin(), B.end(), A.substr(i, j-i)) != B.end()) {
                        dp[j] = true;
                    }

                    if (dp[j] && j== alen) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends
  