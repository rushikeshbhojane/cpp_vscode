#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int K;
        cin >> K;
        int fvCost[K], rvCost[K];
        vector<int> flaggednumbers;
        int costMatrix[K][K] = {0}; 

        for (int a = 0; a < K; a++)
        {
            cin >> fvCost[a];
        }

        for (int a = 0; a < K; a++)
        {
            cin >> rvCost[a];
        }

        sort(fvCost, fvCost + K, greater<int>());
        sort(rvCost, rvCost + K, greater<int>());
        int minCost  = 0, i = 0, j = 0, maxCost = 0;
        for (; i < K && j < K;)
        {
            int minVal = min(fvCost[i], rvCost[j]);
            minCost += minVal;
            if (minVal == fvCost[i]) {
                i++;
            }
            if (minVal == rvCost[j]) {
                j++;
            }
        }

        for(; i < K; i++) minCost += fvCost[i]; 
        for(; j < K; j++) minCost += rvCost[j]; 

        for (int k: rvCost)
        {
            for (int l: fvCost)
            {
                maxCost += min(k, l);
            }
            
        }
        
        printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", minCost, maxCost - minCost);

    }
    return 0;
}