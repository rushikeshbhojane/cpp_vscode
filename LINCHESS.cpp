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
        int N, K;
        scanf("%d %d", &N, &K);
        int temp, minSteps = 2*(1e9), soln = -1;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &temp);
            if ((K % temp == 0))
            {
                if ((K/temp) < minSteps)
                {
                    minSteps = K/temp;
                    soln = temp;
                }
            }
        }

        printf("%d\n", soln);
    }
    

    return 0;
}