#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int H, P;
        scanf("%d %d", &H, &P);

        while (H > 0 && P > 0)
        {
            H -= P;
            P /= 2;
        }
        
        if (H <= 0) printf("1\n");
        else printf("0\n");
    }
    
    return 0;
}