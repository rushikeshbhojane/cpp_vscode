#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'perfectSubstring' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */
 bool isPerfectSubstring(int windowStart, int windowEnd, int k, vector<vector<int>>& totalCount) {
     for (int i = 0; i < 9; i++) {
         int characterCountInWindow = totalCount[windowEnd][i] - totalCount[windowStart-1][i];
         if (characterCountInWindow != 0 || characterCountInWindow != k) {
             return false;
         }
     }
     return true;
 }

int perfectSubstring(string s, int k) {
    int characterCount = s.size();
    vector<vector<int>> totalCount(characterCount + 1, vector<int>(10, 0));
    vector<int> individualCount(10, 0);
    int counter = 0;
    for (char c: s) {
        counter++;
        int currentNumber = c - '0';
        individualCount[currentNumber]++;
        for (int i = 0; i < 9; i++) {
            totalCount[counter][i] = individualCount[i];
        }
    }
    
    int perfectCount  = 0;

    for (int windowSize = k; windowSize <= characterCount; windowSize+=k ) {

        for (int i = 1; i + windowSize - 1 <= characterCount; i++) {
            if (isPerfectSubstring(i, i+windowSize - 1, k, totalCount)) {
                perfectCount++;
            }
        }
    }
    return perfectCount;
}

int main()
{

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    int result = perfectSubstring(s, k);
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}