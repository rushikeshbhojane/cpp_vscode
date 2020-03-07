#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // your code goes here
    int H, D, U, F;
    while(cin >> H
            && cin >> U
            && cin >> D
            && cin >> F
            && H != 0)  {
        int day_count = 0;
        float currentHeight = 0.0, 
                currentAscent = 1.0  * U,
                fatiguePerStep = (1.0 * F/ 100) * currentAscent;
        while (1)
        {
            if (day_count != 0) {
                currentAscent = currentAscent - fatiguePerStep;
            }
            day_count++;
            if (currentAscent > 0) 
                currentHeight = currentHeight + currentAscent;
            if (currentHeight > H) {
                cout << "success on day " << day_count;
                break;
            }
            currentHeight = currentHeight - D;
            if (currentHeight < 0.0) {
                cout << "failure on day " << day_count;
                break;
            }
        }
        cout << "\n";
                
    }
    return 0;
}
