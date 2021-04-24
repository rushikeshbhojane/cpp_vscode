#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;
bool sortFunc(string s1, string s2)
{
    int s1length = s1.length(), s2length = s2.length();
    int minLen = min(s1length, s2length);

    for (int i = 0; i < minLen; i++)
    {
        if (s1.at(i) > s2.at(i)) {
            return true;
        } else if (s1.at(i) < s2.at(i)) {
            return false;
        }
    }
    
    if (s1.length() < s2.length()) {
        return sortFunc(s1, s2.substr(s1.length()));
    } else if (s2.length() < s1.length()) {
        return sortFunc(s1.substr(s2.length()), s2);
    }

    return true;
}
int main()
{
    string line;
    while (getline(cin, line))
    {
        int N;
        sscanf(line.c_str(), "%d", &N);
        if (N == 0) break;

        getline(cin, line);
        istringstream iss(line);
        vector<string> results(istream_iterator<string>{iss},
                                        istream_iterator<string>());
        sort(results.begin(), results.end(), sortFunc);

        ostringstream vts;
        copy(results.begin(), results.end(), ostream_iterator<string>(vts, ""));

        printf("%s\n", vts.str().c_str());
        
    }
    
    return 0;
}