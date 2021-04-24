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
        int N;
        scanf("%d", &N);
        int fingers[N];
        int gloves[N];
        bool front = true, back = true;

        for (int i = 0; i < N; i++) scanf("%d", &fingers[i]);
        for (int i = 0; i < N; i++) scanf("%d", &gloves[i]);

        for (int i = 0; i < N; i++)
        {
            if (fingers[i] > gloves[i]) front = false; 
            if (fingers[i] > gloves[N - i -1]) back = false; 
        }
        
        printf("%s\n", (front && back) ?  "both" : ((front || back) ? ( front ?  "front": "back") : "none")  );
    }
    
    return 0;
}