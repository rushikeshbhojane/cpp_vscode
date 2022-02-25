#include <iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N;
        scanf("%d", &N);
        int people[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &people[i]);
        }

        int minInfected = 1e3, maxInfected = -1;
        int currInfected = 1; 
        for (int i = 1; i < N; i++)
        {
            if (people[i] - people[i-1] <= 2)
            {
                currInfected++;
            }
            else
            {
                minInfected = (minInfected > currInfected)  ? currInfected : minInfected; 
                maxInfected = (maxInfected < currInfected)  ? currInfected : maxInfected; 
                currInfected = 1;
            }
        }
        minInfected = (minInfected > currInfected)  ? currInfected : minInfected; 
        maxInfected = (maxInfected < currInfected)  ? currInfected : maxInfected;
        printf("%d %d\n", minInfected, maxInfected);
    }
    
    return 0;
}