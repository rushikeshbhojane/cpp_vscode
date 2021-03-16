#include<iostream>
typedef long long int LL;
using namespace std;
LL evenNos(LL n) {
    return n/2;
}

LL oddNos(LL n) {
    return n%2 ? n/2 + 1: n/2;
}


int main() {
    int t;
    scanf("%d", &t);
    while (t--)
    {
        LL A, B;
        scanf("%lld %lld", &A, &B);
        LL evenA, evenB, oddA,  oddB;

        evenA = evenNos(A);
        oddA = oddNos(A);
        evenB = evenNos(B);
        oddB = oddNos(B);

        printf("%lld\n", evenA * evenB + oddA * oddB);
    }

    return 0;
}