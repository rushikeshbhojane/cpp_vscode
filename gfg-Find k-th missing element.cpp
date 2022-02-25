#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#define pib pair<int, int>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n1, n2, k;
        scanf("%d %d %d", &n1, &n2, &k);
        map<int, bool> arr1;
        int arr2[n2];

        for (int i = 0; i < n1; i++)
        {
            int temp;
            scanf("%d", &temp);

            arr1[temp] =  false;
        }

        for (int i = 0; i < n2; i++)
        {
            scanf("%d", &arr2[i]);
            if (arr1.find(arr2[i]) != arr1.end())
            {
                arr1[arr2[i]] = true;
            }
        }

        int count = 0;
        bool kThEleFound = false;
        for (pib element: arr1)
        {
            if (!element.second)
            {
                count++;

                if (count == k)
                {
                    printf("%d\n", element.first);
                    kThEleFound = true;
                    break;
                }
            }
        }
        if (!kThEleFound)
        {
            printf("-1\n");
        }
        
    }
    
}