#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bitset>
using namespace std;
int get0OR1(int n)
{
    if(n ==0 || n ==3)
    {
        return 0;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int soln = 0;
        for (int i = n ; i > 0; i--)
        {
            int divisor = 1 << i - 1;
            int quotient = k / divisor;
            quotient %= 4;
            soln = (soln << 1) | get0OR1(quotient);   
        }
        printf("%d\n", soln);
        
    }
    
    return 0;
}