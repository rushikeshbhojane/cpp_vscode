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
        string S, P;
        cin >> S >> P;
        bool isltP0Presnt = false;

        int count[26] = {0};

        for (char c: S) count[c - 'a']++;
        for (int i = 0; i < P.size(); i++)
        {
            if (i != 0 && P[i] < P[i-1]) isltP0Presnt = true; 
            count[P[i] - 'a']--;
        }
        

        string solnString  = "";
        for (int i = 0; i <= 25; i++)
        {
            if (P[0] == ('a' + i))
            {
                if (isltP0Presnt) {
                    solnString += P;
                    for (int j = 0; j < count[i]; j++) solnString += ('a' + i);
                } else {
                    for (int j = 0; j < count[i]; j++) solnString += ('a' + i);
                    solnString += P;
                }
            } else {
                    for (int j = 0; j < count[i]; j++) solnString += ('a' + i);
            }
        }
        cout << solnString << "\n";
    }
    
    return 0;
}