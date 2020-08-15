#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N, M;
        scanf("%d %d", &N, &M);
        int power  = (int)pow(2, N)+1;
        bool arr[power+1];

        for (int i = 0; i <= power; i++)
        {
            arr[i] = 1;
        }
        

        for (int i = 0; i < M; i++)
        {
            int pos;
            scanf("%d", &pos);
            arr[pos] = 0;
        }

        int NTemp  = power, wo = 0;
        while (NTemp > 1)
        {
            for (int i = 1; i < NTemp; i+=2)
            {
                if ((arr[i] && !arr[i+1]) || (!arr[i] && arr[i+1])) wo++;
                arr[i/2 + 1] = (arr[i] || arr[i+1]) ? 1 : 0;
            }
            
            NTemp /= 2;
        }

        printf("%d\n", wo);
                
    }
    
    return 0;
}