#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string tempString;
    while (1)
    {
        getline(cin, tempString);
        int W, H, N;
        sscanf(tempString.c_str(), "%d %d %d", &W, &H, &N);
        if (W == 0 && H == 0 && N == 0) {
            break;
        }


        vector<vector<int> > fillMatrix(W+1, vector<int>(H+1, 0));
        for (int i = 0; i < N; i++)
        {
            /* code */
            getline(cin, tempString);
            int x1, x2, y1, y2;
            sscanf(tempString.c_str(), "%d %d %d %d", &x1, &x2, &y1, &y2);
            int min1 = min(x1, y1), max1 = max(x1, y1);
            int min2 = min(x2, y2), max2 = max(x2, y2);
            for (int i = min1; i <= max1; i++)
            {
                for (int j = min2; j <= max2; j++)
                {
                    fillMatrix[i][j] = 1;
                }
                
            }
            
        }
        int totalEmptyCount = 0;
        for (int i = 1; i <= W; i++)
        {
            for (int j = 1; j <= H; j++)
            {
                if (!fillMatrix[i][j]) {
                    totalEmptyCount++;
                }
            }
            
        }
        if (totalEmptyCount == 0) {
            printf("There is no empty spots.\n");
        } else if (totalEmptyCount == 1) {
            printf("There is one empty spot.\n");
        } else {
            printf("There are %d empty spots.\n", totalEmptyCount);
        }

        getline(cin, tempString);
    }
    
    return 0;
}