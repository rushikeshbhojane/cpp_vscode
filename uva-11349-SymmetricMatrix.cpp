#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;
int main() {
    string tempString;
    int t, i = 0;
    getline(cin, tempString);
    sscanf(tempString.c_str(), "%d", &t);
    while (t--)
    {
        i++;
        int N;
        
        getline(cin, tempString);
        sscanf(tempString.c_str(), "N = %d", &N);
        vector<long long> Matrix;
        for (int i = 0; i < N; i++)
        {
            char *token;
            getline(cin, tempString);
            char cstring[tempString.size() + 1];
            strcpy(cstring, tempString.c_str());
            for (int j = 0; j < N; j++)
            {
                if (j == 0) {
                    token = strtok(cstring, " ");
                } else {
                    token = strtok(NULL, " ");
                }
                Matrix.push_back(atoll(token));
            }            
        }
        bool isSym = true;
        int pointer1 = 0, pointer2 = N*N - 1;

        while (pointer1 <= pointer2)
        {
            if (Matrix[pointer1] < 0 || Matrix[pointer2] < 0 || Matrix[pointer1] != Matrix[pointer2]) {
                isSym = false;
                break;
            }
            pointer1++;
            pointer2--;
        }
        printf("Test #%d: %s.\n", i, (isSym ? "Symmetric": "Non-symmetric") );
    }
    
    return 0;
}