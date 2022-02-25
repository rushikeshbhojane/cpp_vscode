#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here          
        int minEle = 1e4, maxEle = 0, desired = (r*c+ 1)/2;
        for (int i = 0; i < r; i++) {
            minEle =  min(minEle, matrix[i][0]);
            maxEle =  max(maxEle, matrix[i][c-1]);
        }
        
        
        while (minEle < maxEle) {
            int mid = (minEle + (maxEle - minEle)/2);
            int count = 0;
            for (int i = 0; i < r; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) -  matrix[i].begin();
            }

            if (count < desired) {
                minEle = mid + 1;
            } else {
                maxEle =  mid;
            }
        }

        return minEle;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}