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
        double totalLossIncurred = 0;
        scanf("%d", &N);
        while (N--)
        {
            double price, quantity, discount;
            scanf("%lf %lf %lf", &price, &quantity, &discount);
            totalLossIncurred += (price * ((discount * discount)/(10000*1.0))) * quantity;
        }
        printf("%.16lf\n", totalLossIncurred);
    }
    
    return 0;
}