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
        int n;
        scanf("%d", &n);

        int power = 0, nTemp = n + 1;
        bool isWoodall = 0;

        while (nTemp%2 == 0)
        {
            nTemp = nTemp/2;
            power++;
            
            if (nTemp == power)
            {
                isWoodall = 1;
                break;
            }
        }

        printf("%d\n", (isWoodall ? 1 : 0));
        
    }
    
    return 0;
}