#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
void initArray(int arr[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        arr[i] = 0;
    }
    
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N, K;
        scanf("%d %d", &N, &K);
        int FamilyIndex[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &FamilyIndex[i]);
        }

        int FamilyMembersCount[101] = {0};

        int totalExpense = 0, currentExtra = 0;
        bool isCarry =  false;

        for (int i = 0; i < N; i++)
        {
            if (FamilyMembersCount[FamilyIndex[i]] == 0)
            {
                isCarry = true;
            } else {
                int ineff = (FamilyMembersCount[FamilyIndex[i]] == 1) ? 2 : 1; 
                if (currentExtra + ineff <= K)
                {
                    isCarry = true;
                    currentExtra += ineff;
                }
                else
                {
                    isCarry = false;
                    totalExpense += ( K + currentExtra);
                    currentExtra = 0;
                    initArray(FamilyMembersCount, 100);
                }
                
            }
            FamilyMembersCount[FamilyIndex[i]]++;
        }
        
        totalExpense += (K + currentExtra);
        printf("%d\n", totalExpense);
    }
    
    return 0;
}