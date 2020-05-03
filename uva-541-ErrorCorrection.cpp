#include <iostream>
#include <sstream>
using namespace std;
int main () {
    string tempString;
    int dimensions;
    while (cin >> dimensions && dimensions != 0)
    {
        cin.clear();
        int booleanMatrix[dimensions][dimensions], oddSumRowCount = 0 , oddSumColumnCount = 0, oddRow, oddColumn;
        int rowSum[dimensions] = {0}, columnSum[dimensions] = {0};
        for (int i = 0; i < dimensions; i++)
        {
            for (int j = 0; j < dimensions; j++)
            {
                scanf("%d", &booleanMatrix[i][j]);
                rowSum[i] += booleanMatrix[i][j];
                columnSum[j] += booleanMatrix[i][j];
            }
        }

        for (int i = 0; i < dimensions; i++)
        {
            if (rowSum[i]%2 != 0) {
                oddSumRowCount++;
                oddRow =i;
            }

            if (columnSum[i]%2 != 0) {
                oddSumColumnCount++;
                oddColumn =i;
            }

        }
        
        if (oddSumColumnCount == 0 && oddSumColumnCount == 0) {
            printf("OK\n");
        } else if (oddSumColumnCount == 1 && oddSumColumnCount == 1) {
            printf("Change bit (%d,%d)\n", oddRow + 1, oddColumn + 1);
        } else {
            printf("Corrupt\n");
        }

    }
    
    return 0;
}