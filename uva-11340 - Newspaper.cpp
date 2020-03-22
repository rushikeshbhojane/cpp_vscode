#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <sstream>
using namespace std;

int main() {
    // your code goes here
    string tempInputString;
    int t;
    getline(cin, tempInputString);
    sscanf(tempInputString.c_str(), "%d", &t);
    while(t--)  {
        int K, M;
    getline(cin, tempInputString);
    sscanf(tempInputString.c_str(), "%d", &K);
    map<char, int> characterValues;
        for (int i = 0; i < K; i++)
        {
            char c;
            int v;
            getline(cin, tempInputString);
            sscanf(tempInputString.c_str(), "%c %d" , &c, &v);
            characterValues[c] = v; 
        }
        getline(cin, tempInputString);
        sscanf(tempInputString.c_str(), "%d", &M);
        int totalprice = 0;
        for (int i = 0; i < M; i++)
        {
            getline(cin, tempInputString);
            for (char ci: tempInputString)
            {
                if (characterValues.find(ci) != characterValues.end()) {
                    totalprice += characterValues[ci];
                }
            }
            
        }
        printf("%0.2f$\n", totalprice/100.0);
    }
    return 0;
}
