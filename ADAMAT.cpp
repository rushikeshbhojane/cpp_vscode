#include<iostream>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N;
        scanf("%d", &N);
        int arr[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &arr[i][j]);

        int transposeCount[N+1] = {0};

        for (int i = N-1; i >= 1; i--)
        {
            transposeCount[i] =
            (arr[0][i] == (i+1) && ((transposeCount[i+1])%2 == 0))
            || (arr[0][i] != (i+1) && ((transposeCount[i+1])%2 == 1))
            ? transposeCount[i+1]
            : transposeCount[i+1] + 1;
        }
        
        printf("%d\n", transposeCount[1]);
    }
    
    return 0;
}