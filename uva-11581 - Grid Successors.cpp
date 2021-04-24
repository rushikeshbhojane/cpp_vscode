#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#define zeroString "000000000"
using namespace std;

string fg(vector<int> &M) {
    vector<int> MTemp(9, 0);
    string rv = "";
    MTemp[0] = (M[1]+M[3])%2;
    MTemp[1] = (M[0]+M[2]+M[4])%2;
    MTemp[2] = (M[1]+M[5])%2;
    MTemp[3] = (M[0]+M[4]+M[6])%2;
    MTemp[4] = (M[1]+M[5]+M[7]+M[3])%2;
    MTemp[5] = (M[2]+M[4]+M[8])%2;
    MTemp[6] = (M[3]+M[7])%2;
    MTemp[7] = (M[6]+M[4]+M[8])%2;
    MTemp[8] = (M[5]+M[7])%2;
    M.clear();

    M.insert(M.begin(), MTemp.begin(), MTemp.end());

    for (int i = 0; i < 9; i++)
    {
        rv += '0' + M[i]; 
    }
    
    return rv;
}


void AppendRowToVector(vector<int>& M) {
        string ts;
        char c;
        vector<int> rv;
        
        
        getline(cin , ts);
        char cstring[4];
        strcpy(cstring, ts.c_str());
        
        for (int i = 0; i < 3; i++)
        {
            /* code */
            sscanf(cstring + i, "%c", &c);
            rv.push_back(c - '0');
        }
        
        M.insert(M.end(), rv.begin(), rv.end());
}

int main()
{
    string tempString;
    int t;
    
    getline(cin , tempString);
    sscanf(tempString.c_str(), "%d", &t);

    while (t--)
    {
        getline(cin, tempString);

        vector<int> M;
        for (int i = 0; i < 3; i++) AppendRowToVector(M);
        map<string, int> gfmapping;

        string intiialString = "";
        for (int i = 0; i < 9; i++) intiialString += ('0' + M[i]);


        int count = 0;
        gfmapping.insert(make_pair(intiialString, count));

        if (intiialString == zeroString) {
            printf("-1\n");
        }
        else {
            while (1)
            {
                string ms = fg(M);
                if (ms == zeroString)
                {
                    printf("%d\n", count);
                    break;
                }

                if (gfmapping.find(ms) != gfmapping.end()) {
                    printf("%d\n", gfmapping[ms]);
                    break;
                }

                count++;
                gfmapping.insert(make_pair(ms, count));
            }
        }
                
    }
    
    return 0;
}