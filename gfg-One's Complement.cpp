#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bitset>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        bitset<32> bitRes(n);
        string bitResStr = bitRes.to_string();
        bool firstOccuranceFound = false;
        for (int i = 0; i < bitResStr.length(); i++)
        {
            if (bitResStr[i] == '1') firstOccuranceFound = true;
            if (firstOccuranceFound) bitResStr[i] = (bitResStr[i] == '1'  ?  '0' : '1');
        }
        bitset<32> soln(bitResStr);
        printf("%d\n", soln);
        
    }
    
    return 0;
}