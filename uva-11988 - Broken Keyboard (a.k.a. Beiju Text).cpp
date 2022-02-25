#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    string line;
    while (cin >> line)
    {
        string soln = "", finalSoln = "";
        bool homeKeyPress = false;
        for (char c: line)
        {
            if (c == '[')
            {
                if (homeKeyPress)
                {
                    finalSoln = soln + finalSoln;
                }
                soln = "";
                homeKeyPress = true;
            }
            else if (c == ']')
            {
                if (homeKeyPress && !soln.empty())
                {
                    finalSoln = soln + finalSoln;
                }
                homeKeyPress = false;
            }
            else
            {
                if (homeKeyPress)
                {
                    soln += c;
                }
                else
                {
                    finalSoln += c;
                }
            }
        }
        if (homeKeyPress && !soln.empty())
        {
            finalSoln = soln + finalSoln;
        }
        cout << finalSoln << "\n";
    }
    return 0;
}