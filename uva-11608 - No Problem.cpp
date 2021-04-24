#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // your code goes here
    int S, t = 0;
    while (cin >> S && S > -1)
    {
        cin.clear();
        t++;
        int createdSumsArray[12], requiredSumsArray[12];
        for (int i = 0; i < 12; i++)
        {
            scanf("%d", &createdSumsArray[i]);
        }

        for (int i = 0; i < 12; i++)
        {
            scanf("%d", &requiredSumsArray[i]);
        }

        printf("Case %d:\n", t);
        for (size_t i = 0; i < 12; i++)
        {
            /* code */
            if (requiredSumsArray[i] > S) {
                printf("No problem. :(\n");
            } else {
                printf("No problem! :D\n");
                S -= requiredSumsArray[i];
            }
            S += createdSumsArray[i];
        }
        

    }
    
}
