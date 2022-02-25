#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bitset>
using namespace std;
int main()
{
    string input;
    while (getline(cin, input))
    {
        int i;
        sscanf(input.c_str(), "%d", &i);
        string bitResStr = bitset<32>(i).to_string();
        string convertedStr = bitResStr.substr(24,8) + bitResStr.substr(16,8) + bitResStr.substr(8,8) + bitResStr.substr(0,8);
        long result  = 0;

        for (int i = 0; i < 32; i++)
        {
            if (convertedStr[31 - i] == '1')
            {
                result = result | (1 << i);
            }
        }
        
        printf("%d converts to %ld\n", i, result);
    }
    return 0;
}