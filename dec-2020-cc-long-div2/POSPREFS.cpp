#include<iostream>
using namespace std;
void print(int N, int patternUpto, bool restPositive) {

    for (int i = 1; i <= patternUpto; i++)
    {
        if (i % 2 ==0)
        {
            printf("%d", -1 * i);
        } else {
            printf("%d", i);
        }
        if (i != patternUpto) {
            printf(" ");
        }
    }

    if (patternUpto < N && patternUpto > 0) {
        printf(" ");
    }

    for (int i = patternUpto + 1; i <= N; i++)
    {    
        printf("%d", (restPositive ? 1 : -1) * i);
        if(patternUpto < N) printf(" ");
    }

    printf("\n");
    
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N, K;
        scanf("%d %d", &N, &K);

        if (N % 2) {
            if ( K <= N/2) print(N, 2*K - 1, false);
            else print(N, (N - K) * 2, true);
        } else {
            if (N / 2 ==  K) print(N, N, true);
            else if (K < N/2) print(N, 2*K - 1, false);
            else print(N, (N - K) * 2, true);
        }
    }

    return 0;
}