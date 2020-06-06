#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
const int BUDGET = 5 * 1e6;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> Numbers;
        int n;
        while (cin >> n && n != 0)
        {
            Numbers.push_back(n);
        }

        sort(Numbers.begin(), Numbers.end(), greater<int>());

        int total = 0, power = 0;
        bool isPossible = true;
        for (int i : Numbers)
        {
            power++;
            total += pow(i, power);
            if (total > BUDGET/2) {
                isPossible = false;
                break;
            }
        }
        
        if (isPossible) {
            printf("%d\n", 2 * total);
        } else {
            printf("%s\n", "Too expensive");
        }
    }
    
    return 0;
}