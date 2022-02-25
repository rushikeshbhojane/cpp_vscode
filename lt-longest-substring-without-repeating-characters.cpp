#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        int start = 0, end = s.length() -1;
        int maxLen = 0;
        while (start <= end)
        {
            int temp = start, len = 0;
            int charPosition[26] = {
                -1, -1, -1, -1, -1,
                -1, -1, -1, -1, -1,
                -1, -1, -1, -1, -1, 
                -1, -1, -1, -1, -1,
                -1, -1, -1, -1, -1, -1
            };
            while (temp <= end)
            {
                if (charPosition[s[temp] - 'a'] ==  -1)
                {
                    charPosition[s[temp] - 'a'] = temp;
                    temp++; len++;
                    maxLen = max(maxLen, len);
                }
                else
                {
                    temp = charPosition[s[temp] - 'a'] + 1;
                    break;
                }
            }
            start = temp;
        }
        return maxLen;
    }
};

int main()
{
    string s = "abcabcbb";
    printf("%d", Solution::lengthOfLongestSubstring(s));
    printf("%d", Solution::lengthOfLongestSubstring("bbbbb"));
    printf("%d", Solution::lengthOfLongestSubstring("pwwkew"));
    return 0;
}