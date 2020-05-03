#include <iostream>
#include <cstring>
using namespace std;
int canJAcquireI(int i, int j, int N) {
    if (i == j + 1 ||  (i == 0 && j == N-1))
    {
        return true;
    }
    
    return false;
}
int main() {
    string tempString;
    while (1)
    {
        int N, R, C, K;
        getline(cin, tempString);
        sscanf(tempString.c_str(), "%d %d %d %d", &N, &R, &C, &K);
        if (N == 0 && R == 0 && C==0 && K==0) break;

        int territory[R][C] = {0};
        int territoryCopy[R][C] = {0};

        for (int i = 0; i < R; i++)
        {
            getline(cin, tempString);
            char cStyleString[tempString.size()];
            strcpy(cStyleString, tempString.c_str());
            char* token =  strtok(cStyleString, " ");

            for (int j = 0; j < C; j++)
            {
                sscanf(token, "%d", &territory[i][j]);
                token = strtok(NULL, " ");
            }
        }
        

        for (int k = 0; k < K; k++)
        {
            /* code */
            copy(&territory[0][0], &territory[0][0] + R * C, &territoryCopy[0][0]);

            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    // left
                    if (j - 1 >= 0)
                    {
                        if (canJAcquireI(territory[i][j], territory[i][j-1], N)) {
                            territoryCopy[i][j] = territory[i][j-1];
                        }
                    }

                    //top
                    if (i - 1 >= 0 )
                    {
                        if (canJAcquireI(territory[i][j], territory[i-1][j], N)) {
                            territoryCopy[i][j] = territory[i-1][j];
                        }
                    }

                    //right
                    if (j + 1 < C)
                    {
                        if (canJAcquireI(territory[i][j], territory[i][j+1], N)) {
                            territoryCopy[i][j] = territory[i][j+1];
                        }
                    }


                    //bottom
                    if (i + 1 < R)
                    {
                        if (canJAcquireI(territory[i][j], territory[i+1][j], N)) {
                            territoryCopy[i][j] = territory[i+1][j];
                        }
                    }



                }
            }
            
            copy(&territoryCopy[0][0], &territoryCopy[0][0] + R * C, &territory[0][0]);

        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                /* code */
                printf("%d", territory[i][j]);
                if (j != C-1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
        
    }
    
    return 0;
}