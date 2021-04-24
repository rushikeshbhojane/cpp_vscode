#include <iostream>
#include <vector>
using namespace std;
#define REP(i,a,b) for(int i = int(a); i <= int(b); i++)
#define REV(i,a,b) for(int i = int(a); i >= int(b); i--)
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<int> > wall(9, vector<int>());
        REP(i, 0, 8)
        {
            REP(j,0,i)
            {
                wall[i].push_back(-1);
            }
        }
        for (int i = 0; i <= 8; i += 2)
        {
            for (int j = 0; j <= i; j+=2)
            {
                cin >> wall[i][j];        
            }
        }
        

        // build the base wall
        for (int i = 1; i <= 8; i+=2)
        {
            /* code */
            wall[8][i] =  (wall[6][i-1]- wall[8][i-1] - wall[8][i+1])/2;
        }

        REV(i, 7, 0)
            REP(j,0,i)
                wall[i][j] = wall[i+1][j] + wall[i+1][j+1];
        
        REP(i,0,8)
        {
            REP(j,0,i)
            {
                printf("%d", wall[i][j]);
                if (j != i) {
                    printf(" ");
                } else {
                    printf("\n");
                }
            }
        }

    }
    return 0;
}