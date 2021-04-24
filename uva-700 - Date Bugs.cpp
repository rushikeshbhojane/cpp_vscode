#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{   
    string input;
    int ic = 0;
    while (getline(cin, input))
    {
        ic++;
        int n;
        sscanf(input.c_str(), "%d", &n);
        if (n == 0) break;

        vector<vector<int> > arr (n);
        for (int i = 0; i < n; i++)
        {
            int x, a ,b;
            getline(cin, input);
            sscanf(input.c_str(), "%d %d %d", &x, &a, &b);

            int diff1 = b - a;
            int diff2 = x - a;

            int counter  = 1;
            int base  = a +  (counter*diff1) + diff2;
            while (base < 10000)
            {
                arr[i].push_back(base);
                counter++;
                base  = a +  (counter*diff1) + diff2;
            }
 
        }

        vector<int> soln_vector(arr[0]);
        vector<int>::iterator it;
        bool neverPossible =  false;
        for (int i = 1; i < n; i++)
        {
            vector<int> soln_vector2(soln_vector.size() + arr[i].size());
            vector<int>::iterator ls = set_intersection(soln_vector.begin(),
                                                                soln_vector.end(),
                                                                arr[i].begin(),
                                                                arr[i].end(),
                                                            soln_vector2.begin());
            if(soln_vector2[0] == 0) {
                neverPossible = true;
                break;
            }
            soln_vector.clear();
            for (vector<int>::iterator j = soln_vector2.begin(); j < soln_vector2.end(); j++)
            {
                if (*j == 0) break;
                soln_vector.push_back(*j);
            }
        }

        if (ic != 1)
        {
            printf("\n");
        }

        printf("Case #%d:\n", ic);
        if (neverPossible)
        {
            printf("Unknown bugs detected.\n");
        }
        else
        {
            sort(soln_vector.begin(), soln_vector.end());
            printf("The actual year is %d.\n", soln_vector[0]);
        }
        
        
        
    }
    return 0;
}