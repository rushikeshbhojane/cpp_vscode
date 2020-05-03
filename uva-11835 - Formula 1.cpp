#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int main() {
    string tempString;
    while (1)
    {
        int G,P;
        getline(cin, tempString);
        sscanf(tempString.c_str(), "%d %d", &G, &P);
        if (G == 0 && P == 0) break; 
        int postions[G+1][P+1] = {0};
        for (int i = 1; i <= G; i++)
        {
            getline(cin, tempString);
            char cStyleString[tempString.size()];
            strcpy(cStyleString, tempString.c_str());
            char* token =  strtok(cStyleString, " ");

            for (int j = 1; j <= P; j++)
            {
                sscanf(token, "%d", &postions[i][j]);
                token = strtok(NULL, " ");
            }
            
        }

        int S;
        getline(cin, tempString);
        sscanf(tempString.c_str(), "%d", &S);

        for (int i = 0; i < S; i++)
        {
            getline(cin, tempString);
            char cStyleString[tempString.size()];
            strcpy(cStyleString, tempString.c_str());
            char* token =  strtok(cStyleString, " ");
            int K;
            int points[P+1] = {0};

            sscanf(token, "%d", &K);

            for (int j = 1; j <= K; j++)
            {
                token = strtok(NULL, " ");
                sscanf(token, "%d", &points[j]);
            }

            
            int individualpoints[P+1] = {0};
            for (int j = 1; j <= G; j++)
            {
                for (int k = 1; k <= P; k++)
                {
                    individualpoints[k] += points[postions[j][k]];
                }
                    
            }
            
            vector<int> winners;
            int maxv = -1;

            for (int j = 1; j <= P; j++)
            {
                if (individualpoints[j] > maxv) {
                    winners.clear();
                    winners.push_back(j);
                    maxv = individualpoints[j];
                } else if (individualpoints[j] == maxv) {
                    winners.push_back(j);
                }
            }

            for (int& j: winners) {
                printf("%d", j);
                if (&j != &winners.back()) {
                    printf(" ");
                }
            }
            
            printf("\n");
        }
    }
    
    
    return 0;
}