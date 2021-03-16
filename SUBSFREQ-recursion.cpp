#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define pii std::pair<int, int>

void calcCountHelper(
    vector<int>& sequence,
    vector<int> solnIntermediate,
    vector<int>& solnFinal,
    int N, int index,
    pii maxEleCount
) {
    if (index < N) {

        calcCountHelper(
            sequence, solnIntermediate, solnFinal,
            N, index + 1, maxEleCount
        );

        solnIntermediate[sequence[index]]++;
        if (solnIntermediate[sequence[index]] > maxEleCount.second
            || (
                solnIntermediate[sequence[index]] == maxEleCount.second
                &&  sequence[index] < maxEleCount.first
            ) ) {
            maxEleCount.first = sequence[index]; 
            maxEleCount.second = solnIntermediate[sequence[index]]; 
        }

        solnFinal[maxEleCount.first]++;

        calcCountHelper(
            sequence, solnIntermediate, solnFinal,
            N, index + 1, maxEleCount
        );
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N;
        scanf("%d", &N);
        vector<int> sequence(N+1, 0);
        vector<int> solnFinal(N+1, 0);
        vector<int> solnIntermediate(N+1, 0);

        rep(i, N) scanf("%d", &sequence[i+1]);

        pii maxEleCount =  make_pair(-1, -1);

        calcCountHelper(
            sequence,
            solnIntermediate,
            solnFinal,
            N+1, 1,
            maxEleCount
        );

        for (int i = 1; i < N+1; i++)
        {
            printf("%d", solnFinal[i]);
            if (i != N) {
                printf(" ");
            }
        }

        printf("\n");
        
    }
    
    return 0;
}