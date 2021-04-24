#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>
using namespace std;
int arguements(int arr[], int l, int r)
{
    int count[101] = {0};

    for (int i = l; i <= r; i++)
    {
        count[arr[i]]++;
    }
    
    int totalArguements = 0;

    for (int i = 0; i < 101; i++)
    {
        totalArguements += (count[i] > 1 ?  count[i]: 0 );
    }
    
    return totalArguements;
}
int main()
{ 
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N, K;
        scanf("%d %d", &N, &K);
        int FamilyIndex[N+1] = {0};
        int dp[N+1] = {0};
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &FamilyIndex[i]);
        }

        for (int i = 1; i <= N; i++)
        {
            dp[i] = dp[i-1] + K;

            for (int j = i-1; j > 0; j--)
            {
                dp[i] = min(dp[i], dp[j-1] + K  + arguements(FamilyIndex, j, i));
            }
            
        }

        printf("%d\n", dp[N]);
        
    }
    return 0;
}