// { Driver Code Starts
#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
using namespace std; 

class Solution {
public:
    string countAndSay(int n) {
        string soln = "1";
        for (int i = 2; i <= n; i++) {
            string temp = "";
            char current  = soln[0];
            int currentCount  = 1;
            for (int i = 1; i < soln.length(); i++) {
                if (soln[i] == current) {
                    currentCount++;
                } else {
                    temp += to_string(currentCount) + current;
                    current  = soln[i];
                    currentCount = 1;
                }
            }
            temp += to_string(currentCount) + current;
            soln = temp;
        }
        
        return soln;
        
    }
};

int main () {
    Solution* s = new Solution();
    cout << s->countAndSay(2) << endl;
    cout << s->countAndSay(3) << endl;
    cout << s->countAndSay(4) << endl;
    cout << s->countAndSay(5) << endl;
    return 0;
}