#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N, X;
        scanf("%d %d", &N, &X);
        int arr[N];
        for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
        int xCounter = 0;
        for (int i = 0; i < N-1 && xCounter < X; i++)
        {
            while (arr[i] != 0 && xCounter < X)
            {
                bool operationNotPerformed = true;
                int p = log2(arr[i]);
                for (int j = i+1; j < N-1; j++) {
                    if ((arr[j] ^ (1 << p)) < arr[j]) {
                        xCounter++;
                        operationNotPerformed = false;
                        arr[j] = (arr[j] ^ (1 << p));
                        arr[i] = (arr[i] ^ (1 << p));
                        break;
                    }
                }
                if (operationNotPerformed)
                {
                    arr[i] = (arr[i] ^ (1 << p));
                    arr[N-1] = (arr[N-1] ^ (1 << p));
                }
            }
            
        }

        if (xCounter < X) {
            int XDiff = X - xCounter;
            if ( XDiff % 2 != 0) {
                if ((N == 2)) {
                    arr[N-1] = arr[N-1] ^ 1;
                    arr[N-2] = arr[N-2] ^ 1;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            printf("%d", arr[i]);
            if(i != N-1) printf(" ");
        }

        printf("\n");        
    }

    return 0;
}