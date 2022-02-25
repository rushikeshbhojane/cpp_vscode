#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    vector<int> charCount(26, 0);
    for (char c: s) {
            charCount[c - 'a']++;
    }
    
    map<int, int> countMap;
    for (int i = 0; i< 26; i++) {
        if (charCount[i] != 0) {
            countMap[charCount[i]]++;
        }
    }
    
    if (countMap.size() == 1) {
        return "YES";
    }
    
    if (countMap.size() == 2) {
        vector<pair<int, int>> counts;
        for (pair<int, int> count: countMap) {
            counts.push_back(count);
        }
        
        if (counts[0].second == 1) {
            if (counts[0].first - 1 == counts[1].first) {
                return "YES";
            }

            if (counts[0].first - 1 == 0) {
                return "YES";
            }
        }

        if (counts[1].second == 1) {
            if (counts[1].first - 1 == counts[0].first) {
                return "YES";
            }

            if (counts[1].first - 1 == 0) {
                return "YES";
            }
        }
        
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
