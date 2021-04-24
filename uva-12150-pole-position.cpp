#include <iostream>
#include <cstring>
using namespace std;
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
int main() {
    int N;
    while (cin >> N && N != 0)
    {
        cin.clear();
        int positions[N + 1] = {0};
        bool isPossible = true;
        REP(i,1,N)
        {
            int carNo, displacement;
            scanf("%d %d", &carNo, &displacement);
            if (isPossible &&  
                (i + displacement >= 1) &&
                (i + displacement <= N) &&
                positions[i + displacement] == 0) {
                positions[i + displacement] = carNo;
            } else {
                isPossible = false;
            }
        }

        if (isPossible) {
            REP(i,1, N) {
                printf("%d",positions[i]);
                if (i != N) {
                    printf(" ");
                }
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
        
    }
    
    return 0;
}