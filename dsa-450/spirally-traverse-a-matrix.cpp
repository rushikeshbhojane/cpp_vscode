// { Driver Code Starts
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std; 

 // } Driver Code Ends

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int left = 0, right = c-1, top =0, bottom = r - 1, dr = 0;
        vector<int> spiral;
        while (left <= right && top <= bottom) {
            if (dr == 0) {
                for(int i = left; i <= right; i++) {
                    spiral.push_back(matrix[top][i]);
                }
                top++;
                dr = 1;
            } else if (dr == 1) {
                for(int i = top; i <= bottom; i++) {
                    spiral.push_back(matrix[i][right]);
                }
                right--;
                dr = 2;
            } else if (dr == 2) {
                for(int i = right; i >= left; i--) {
                    spiral.push_back(matrix[bottom][i]);
                }
                bottom--;
                dr = 3;
            } else {
                for(int i = bottom; i >=  top; i--) {
                    spiral.push_back(matrix[left][i]);
                }
                left++;
                dr = 0;
            }
        }
        
        return spiral;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends