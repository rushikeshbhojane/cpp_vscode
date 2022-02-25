#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long N;
        long long niceswaps = 0;
        scanf("%lld", &N);
        long long SUM = N*(N+1)/2;
        if (SUM%2) {
            printf("%d\n", 0);
        } else {
            long double root = sqrt(1.0+4.0*SUM*1.0);
            long long X = (int) ((-1.0 + root)/2.0);
            long long SUMX = X*(X+1)/2;
            niceswaps += (N-X);
            if (SUMX == SUM/2) {
                niceswaps += (X* (X-1))/2;
                niceswaps += ((N-X)* (N-X-1))/2;
            }
            printf("%lld\n", niceswaps);
        }
    }
    
    return 0;
}