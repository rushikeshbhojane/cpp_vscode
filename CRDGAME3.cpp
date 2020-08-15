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
        int C, R;
        scanf("%d %d", &C, &R);
        int nC = ceil(C*1.0/9);
        int nR = ceil(R*1.0/9);
        printf("%d %d\n", (nC < nR ?  0 : 1) , (nC < nR ?  nC : nR));
    }
    
    return 0;
}