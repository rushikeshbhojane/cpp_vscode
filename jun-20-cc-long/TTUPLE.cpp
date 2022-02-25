#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
/*
subset of elements 1,2,3
single element: [1] [2] [3]
two elements: [1 2] [2 3] [1 3]
all three: [1 2 3]
*/
int findSteps(int p, int q, int r,
                int a, int b, int c, int stepNo) {
    int aBYp = a/p;
    int bBYq = b/q;
    int cBYr = c/r;

    int aMp = a - p;
    int bMq = b - q;
    int cMr = c - r;

    int minBY = min(aBYp, bBYq, cBYr);
    int maxBY = max(aBYp, bBYq, cBYr);


    return 3;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p, q, r;
        int a, b, c;
        cin >> p >> q >> r;
        cin >> a >> b >> c;
        int noOfSteps;
        printf("%d", );
        /* code */
    }
    
    return 0;
}