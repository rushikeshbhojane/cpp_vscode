#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;
struct keywordObj
{
    string keyword;
    vector<string> line;
    int titleNo;
    int wordNo;

    keywordObj(string _keyword, int _titleNo, int _wordNo, vector<string> _line) {
        keyword = _keyword;
        titleNo = _titleNo;
        wordNo = _wordNo;
        line = _line;
    }
};


bool keywordSortFunction(keywordObj* k1, keywordObj* k2)
{
    if (strcmp((k1 -> keyword).c_str(), (k2 -> keyword).c_str()) < 0)
        return true;
    else if (strcmp((k1 -> keyword).c_str(), (k2 -> keyword).c_str()) > 0)
        return false;
    else
        if (k1 -> titleNo < k2 -> titleNo) {
            return true;
        } else if (k1 -> titleNo > k2 -> titleNo) {
            return false;
        } else {   
            if (k1 -> wordNo < k2 -> wordNo) {
                return true;
            }
        }
    return false;
}

int main()
{
    string line;
    vector<string> ignoredWords;
    vector<keywordObj*> keywords;
    while (getline(cin, line))
    {
        if (line == "::")
        {
            break;
        }
        transform(line.begin(), line.end(), line.begin(), ::tolower); 
        ignoredWords.push_back(line);
    }

    int titleNo  = -1;
    while (getline(cin, line))
    {
        if(line == "end") break;
        titleNo++;
        transform(line.begin(), line.end(), line.begin(), ::tolower); 
        istringstream iss(line);
        vector<string> results(istream_iterator<string>{iss},
                                        istream_iterator<string>());
        
        int wordNo = -1;
        for (string s: results)
        {
            wordNo++;
            if (find(ignoredWords.begin(), ignoredWords.end(), s)
                    == ignoredWords.end())
            {
                keywordObj* k = new keywordObj(s, titleNo, wordNo, results);
                keywords.push_back(k);
            }
        }
        
    }

    sort(keywords.begin(), keywords.end(), keywordSortFunction);

    for (keywordObj* k: keywords)
    {
        int lineSize = (k -> line).size();
        for (int i = 0; i < lineSize ; i++)
        {
            if (i == k -> wordNo) {
                transform(k -> line[i].begin(), k -> line[i].end(), k -> line[i].begin(), ::toupper);
                const char* cmyStr = (k -> line[i]).c_str();
                printf("%s", cmyStr);
            } else {
                const char* cmyStr = (k -> line[i]).c_str();
                printf("%s", cmyStr);
            }

            if (i != lineSize - 1) printf(" "); 
        }
        printf("\n");
    }
    
    return 0;
}