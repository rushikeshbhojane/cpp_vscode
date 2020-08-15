#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    string line;
    getline(cin, line);
    int t;
    sscanf(line.c_str(), "%d", &t);
    while (t--)
    {
        string S, P;
        getline(cin, S);
        getline(cin, P);

        int count[26] = {0};

        for (char c: S) count[c - 'a']++;
        for (char c: P) count[c - 'a']--;

        string solnString  = "";
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < count[i]; j++) solnString += ('a' + i);
            if (P[0] == ('a' + i))
            {
                solnString += P;
            }
        }
        printf("%s\n", solnString.c_str());
    }
    
    return 0;
}