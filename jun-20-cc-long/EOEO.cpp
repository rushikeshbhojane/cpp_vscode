#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long TS;
        cin >> TS;

        if (TS % 2 != 0) {
            printf("%lld\n", TS/2);
        } else {
            long long cnt = 1, TSTemp = TS;
            while (TSTemp%2 == 0) {
                cnt *= 2;
                TSTemp /= 2;
            }
            if (TSTemp % 2 == 0) TSTemp--;
            printf("%lld\n", TSTemp/2);
        }
    }
    
    return 0;
}