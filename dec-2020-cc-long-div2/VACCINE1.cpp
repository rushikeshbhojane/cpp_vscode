#include<iostream>
using namespace std;
int main() {
    int D1, V1, D2, V2, P;
    scanf("%d %d %d %d %d",&D1, &V1, &D2, &V2, &P);
    int total = 0, dayNo = 0;
    while (total < P)
    {
        dayNo++;
        total += (
            (dayNo >= D1 ? V1: 0)
            + (dayNo >= D2 ? V2: 0)
        );
        if (total == P) break; 
    }
    printf("%d\n", dayNo);

    return 0;
}