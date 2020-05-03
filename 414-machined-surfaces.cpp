#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
#include <string>
#include <cstring>
using namespace std;
int main () {
    string input;
    int no_of_lines;
    while (cin >> no_of_lines && no_of_lines != 0)
    {
        /* code */
        getline(cin, input);
        int blanksLength[no_of_lines] = {0}, min_blank_count = 0XFFFFFFF, solution = 0;
        for (int i = 0; i < no_of_lines; i++)
        {
            /* code */    
            int blank_count = 0;
            getline(cin, input);
            for (char c: input)
            {
                /* code */
                if (c == ' ') {
                    blank_count++;
                }
            }
            blanksLength[i] = blank_count;
            min_blank_count = min(min_blank_count, blank_count);
        }
        for (int i = 0; i < no_of_lines; i++)
        {
            solution += (blanksLength[i] - min_blank_count);
        }

        cout << solution << "\n";
    }
    
    return 0;
}