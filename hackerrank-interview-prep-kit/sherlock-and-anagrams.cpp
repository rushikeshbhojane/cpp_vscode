#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int sherlockAndAnagrams(string s) {
    vector<string> substrings;
    for (int i = 1; i <=  s.length(); i++) {
        for (int j = 0; j + i <= s.length(); j++) {
            substrings.push_back(s.substr(j, i));
        }
    }
    
    vector<vector<int>> smap;
    
    for (string s : substrings) {
        vector<int> count(26, 0);
        for (char c: s) {
            count[c - 'a']++;
        }
        smap.push_back(count);
    }
    
    int anagrams = 0;
    for (int i = 0; i < smap.size(); i++) {
        for (int j = i+1; j < smap.size(); j++) {
            if (i  !=  j) {
                bool isAnagram = true;
                for (int k = 0; k < 26; k++) {
                        if (smap[i][k] != smap[j][k]) {
                           isAnagram = false;
                           break; 
                        }
                }
                if (isAnagram) {
                    anagrams++;
                }
            }
        }
    }
    
    return anagrams;
}

int main()
{

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        cout << result << "\n";
    }


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
