#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N;
        scanf("%d", &N);
        int S[N+1] = {0};
        int soln[N+1] = {0};

        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &S[i]);
        }
        
        for (int j = 1; j <= N; j++)
        {
            int total = 0;
            for (int k = j-1; k > 0; k--)
            {
                if (S[j] < total) break;
                else soln[k]++;
                total += S[k];
            }
            
            total = 0;
            for (int k = j + 1; k <= N; k++)
            {
                if (S[j] < total) break;
                else soln[k]++;
                total += S[k];
            }
            
        }
        
        for (int j = 1; j <= N; j++)
        {
            printf("%d", soln[j]);
            if(j != N) printf(" ");
        }
        
        printf("\n");
    }
    
    return 0;
}