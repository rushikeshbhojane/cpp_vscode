#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int loss = 0;

        while (N--)
        {
            int inp;
            cin >> inp;
            if (inp > K) {
                loss += inp - K;
            }
        }
        
        printf("%d\n", loss);
        
        /* code */
    }
    
    return 0;
}