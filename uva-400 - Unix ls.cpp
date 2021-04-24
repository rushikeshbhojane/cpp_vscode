#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    string line;
    while (getline(cin, line))
    {
        int N, longest = 0;
        sscanf(line.c_str(), "%d", &N);
        vector<string> fileNames;
        for (int i = 0; i < N; i++)
        {
            getline(cin, line);
            fileNames.push_back(line);
            if (line.length() > longest) {
                longest = line.length();
            }
        }
        int noOfCols = (60 - longest) / (longest + 2) + 1;
        int noOfRows = ceil(N * 1.0/ noOfCols);

        sort(fileNames.begin(), fileNames.end());
        vector<vector<string> > opFileNames(noOfRows, vector<string>());

        for (int i = 0; i < N; i += noOfRows)
        {
            for (int j = 0; j < noOfRows; j++)
            {
                if (i + j < N) {
                    opFileNames[j].push_back(fileNames[i+j]);
                } else {
                    break;
                }
            }
            
        }

        for (int i = 0; i < 60; i++)
        {
            printf("-");
        }
        printf("\n");
        
        for (int i = 0; i < noOfRows; i++)
        {
            for (int j = 0; j < opFileNames[i].size(); j++)
            {
                if(j ==  opFileNames[i].size() - 1) {
                    printf("%s\n", opFileNames[i][j].c_str());
                } else {
                    printf("%s", opFileNames[i][j].c_str());
                    for (int k = 0; k < longest + 2 - opFileNames[i][j].size(); k++)
                    {
                        printf(" ");
                    }
                    
                }
            }            
        }
        
            
        
    }
    
    return 0;
}