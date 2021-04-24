#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) {
              if(a[0] < b[0]) return true;
              else if((a[0] == b[0]) && a[1] < b[1]) return true;
              else return false;
            });
        vector<vector<int>> solution;
        vector<int> current;
        current.push_back(intervals[0][0]);
        current.push_back(intervals[0][1]);

        for(int i = 1; i < intervals.size(); i++) {
            if(current[1] < intervals[i][0] || current[0] > intervals[i][1]) {
                // entirely out of bounds
                solution.push_back(current);
                current.clear();
                current.push_back(intervals[i][0]);
                current.push_back(intervals[i][1]);
            } else {
                current.clear();
                current.push_back(min(current[0], intervals[i][0]));
                current.push_back(min(current[1], intervals[i][1]));
            }
        }
        
        if(!solution.empty()
           && (solution.back()[0] != current[0] 
                    && solution.back()[1] != current[1])) {
            solution.push_back(current);
        } else if (solution.empty()) {
            solution.push_back(current);
        }
        
        return solution;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> vect { vector<int> {1,4} , {4, 5}};
    s.merge(vect);

    return 0;
}