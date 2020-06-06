#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<string> permutations;
        permutations.push_back(line);
        string line1 = line, line2 = line;
        for (int i = 0 ; i < 10; i++) {
            next_permutation(line1.begin(), line1.end());
            permutations.push_back(line1);
        }

        for (int i = 0 ; i < 10; i++) {
            prev_permutation(line2.begin(), line2.end());
            permutations.insert(permutations.begin(), line2);
        }

        int largesMinimumAbsoluteDistance = -1;
        string solnString;
        for (string s: permutations)
        {
            int minimumAbsDistance = 1e2;

            for (int i = 1 ; i < s.length(); i++)
            {
                int dist = abs(s[i] - s[i-1]);
                if (dist < minimumAbsDistance)
                {
                    minimumAbsDistance = dist;
                }
            }
            
            if (minimumAbsDistance > largesMinimumAbsoluteDistance) {
                largesMinimumAbsoluteDistance = minimumAbsDistance;
                solnString = s;
            }
        }

        printf("%s%d\n", solnString.c_str(), largesMinimumAbsoluteDistance);
    }
    
    return 0;
}