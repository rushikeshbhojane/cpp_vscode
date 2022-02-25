#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int D, N;
        int atRiskCount = 0, normalCount = 0;
        scanf("%d %d", &N, &D);
        for (int i = 0; i < N; i++)
        {
            int temp;
            scanf("%d", &temp);
            if (temp <= 9 || temp >= 80) atRiskCount++; 
        }
        normalCount = N - atRiskCount;
        int NoOfDays = ceil(normalCount * 1.0/ D) + ceil(atRiskCount * 1.0/ D);
        printf("%d\n", NoOfDays);
    }

    return 0;
}