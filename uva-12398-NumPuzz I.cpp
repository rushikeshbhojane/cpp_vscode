#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isInBounds(int i, int j) {
    if (i < 0 || i > 2) {
        return false;
    }

    if (j < 0 || j > 2) {
        return false;
    }

    return true;
}
void moduloIncrement(int& i) {
    if(i == 9) {
        i = 0;
    } else {
        i++;
    }
}
int main()
{
    string line;
    int t;
    while (getline(cin , line))
    {
        t++;
        vector<vector<int> > intial(3, vector<int> (3, 0));
        if (!line.empty()) {
            reverse(line.begin(), line.end());

            for (char c: line) {
                int i  =  (c - 'a' ) / 3;
                int j = (c - 'a')  % 3;

                moduloIncrement(intial[i][j]);
                if (isInBounds(i-1, j)) moduloIncrement(intial[i-1][j]); 
                if (isInBounds(i, j + 1)) moduloIncrement(intial[i][j+1]); 
                if (isInBounds(i + 1, j)) moduloIncrement(intial[i+1][j]); 
                if (isInBounds(i, j - 1)) moduloIncrement(intial[i][j-1]); 
            }
        }

        printf("Case #%d:\n", t);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d", intial[i][j]);
                if(j != 2) {
                    printf(" ");
                }
            }
            printf("\n");
        }
        
    }
    
    return 0;
} 