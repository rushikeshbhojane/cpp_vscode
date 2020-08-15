#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bitset>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);
        int soln = n;
        bitset<32> orig(n);
        int diff = 0;

        string origString = orig.to_string();
        bool afterFirstOccurance = false;
        for (int i = 0; i < origString.length(); i++)
        {
            if (afterFirstOccurance
                    && origString[i] == '0')
            {
                diff = diff | (1 << (31 - i));
                soln = soln | (1 << (31 - i));
            }

            if (origString[i] == '1')
            {
                afterFirstOccurance = true;
            }
        }

        printf("%d %d\n", diff, soln);
         

    }
    
    return 0;
}