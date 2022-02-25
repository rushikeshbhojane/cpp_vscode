#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    int N, Q;
    scanf("%d %d", &N , &Q);
    long long arr[N+1];
    for (int i = 1; i < N+1; i++)
    {
        scanf("%lld", &arr[i]);
    }

    // Pre processing prefix tree
    int onesPrefix[31][N+1] = {0};
    int zeroesPrefix[31][N+1] = {0};

    for (int i = 0; i < 31; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (1 << i & arr[j]) (onesPrefix[i][j] = onesPrefix[i][j-1] + 1) && (zeroesPrefix[i][j] = zeroesPrefix[i][j-1]);
            else (zeroesPrefix[i][j] = zeroesPrefix[i][j-1] + 1) && (onesPrefix[i][j] = onesPrefix[i][j-1]);
        }
    }
    
    for (int i = 0; i < Q; i++)
    {
        int L, R;
        scanf("%d %d", &L, &R);
        long long soln = 0;
        for (int j = 0; j < 31; j++)
        {
            int zeroes = zeroesPrefix[j][R] - zeroesPrefix[j][L-1];
            int ones = onesPrefix[j][R] - onesPrefix[j][L-1];

            if (zeroes > ones)
            {
                soln = soln | (1 << j);
            }
        }
        printf("%lld\n", soln);
    }
    
    return 0;
}