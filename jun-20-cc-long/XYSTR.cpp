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
        string s;
        cin >> s;
        int count = 0;

        for (int i = 1; i < s.length(); i++)
        {
            char before = s[i-1];
            if (s[i] != before) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }

        printf("%d\n", count);
                
    }
    
    return 0;
}