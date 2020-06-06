#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    int total = 0;
    vector<int> Numbers;
    string line;
    while (getline(cin, line))
    {
        total++;
        int number;
        sscanf(line.c_str(), "%d", &number);
        auto const insertion_point =  
                upper_bound(Numbers.begin(), Numbers.end(), number);
        Numbers.insert(insertion_point, number);
        if (total % 2 != 0) {
            printf("%d\n", Numbers[total/2]);
        }  else {
            printf("%d\n", (Numbers[total/2] + Numbers[total/2 - 1]) / 2);
        }
    }
    
    return 0;
}