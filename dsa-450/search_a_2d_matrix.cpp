#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> firstEle;
        for (int  i = 0; i < matrix.size(); i++)  firstEle.push_back(matrix[i][0]);
        int rowindex = lower_bound(firstEle.begin(), firstEle.end(), target) - firstEle.begin();

        if (rowindex == 0 && firstEle[rowindex] > target) {
            return false;
        }
        if (rowindex > 0 && firstEle[rowindex] > target) rowindex--; 
        cout << lower_bound(firstEle.begin(), firstEle.end(), 0) - firstEle.begin();
        cout << lower_bound(firstEle.begin(), firstEle.end(), 1) - firstEle.begin();
        cout << lower_bound(firstEle.begin(), firstEle.end(), 5) - firstEle.begin();
        cout << lower_bound(firstEle.begin(), firstEle.end(), 10) - firstEle.begin();
        cout << lower_bound(firstEle.begin(), firstEle.end(), 11) - firstEle.begin();
        cout << lower_bound(firstEle.begin(), firstEle.end(), 15) - firstEle.begin();
        cout << lower_bound(firstEle.begin(), firstEle.end(), 20) - firstEle.begin();
        cout << lower_bound(firstEle.begin(), firstEle.end(), 23) - firstEle.begin();
        cout << lower_bound(firstEle.begin(), firstEle.end(), 30) - firstEle.begin();

        if (find(matrix[rowindex].begin(), matrix[rowindex].end(), target) != matrix[rowindex].end()) {
            return true;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1}};
    Solution* s = new Solution();
    s->searchMatrix(matrix, 3); 

    return 0;
}