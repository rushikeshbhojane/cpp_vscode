#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int GetPerimeter(int x, int y, int z)
{
    if ((x + y > z)
        && (y + z > x)
        && (x + z > y))
    {
        return x + y + z;
    }
    return 0;
}

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    int sides[N + 1];

    for (int i = 1; i <= N; i++) scanf("%d", &sides[i]);

    for (int i = 0; i < Q; i++)
    {
        int qType, arg1, arg2;
        scanf("%d %d %d", &qType, &arg1, &arg2);

        if (qType == 1) sides[arg1] = arg2;
        else if (qType == 2)
        {
            int maxPerimeter = 0;
            for (int j = arg1; j <= arg2 - 2; j++)
                for (int k = j + 1; k <= arg2 - 1; k++)
                    for (int l = k + 1; l <= arg2; l++)
                    {
                        maxPerimeter = max(maxPerimeter,
                                            GetPerimeter(sides[j], sides[k], sides[l]));
                    }
            printf("%d\n", maxPerimeter);
        }
        
    }
    
    
    return 0;
}