#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N, H, maxEle = -1;
        double minAvg = 0;
        scanf("%d %d", &N, &H);
        int arr[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
            minAvg += (arr[i] * 1.0 / H);
            maxEle = max(maxEle, arr[i]);
        }

        int low = ceil(minAvg), high = maxEle, solnSpeed = 0;
        while (low <= high)
        {
            int  hours = 0;
            int mid = (low + high)>>1;
            for (int j = 0; j < N; j++)
            {
                hours += ceil(arr[j] * 1.0 / mid);
            }
            if(hours > H)
            {
                low = mid + 1;
            } else {

                high = mid - 1;
                solnSpeed = mid;
            }

        }
        
        printf("%d\n", solnSpeed);
        
    }
    
    return 0;
}