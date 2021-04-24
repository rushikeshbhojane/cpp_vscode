#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bitset>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) && n != 0)
    {
        bitset<32> bits(n);
        string bitString = bits.to_string();
        int a = 0, b = 0;
        reverse(bitString.begin(), bitString.end());
        vector<int> indexes;
        for (int i = 0; i < 32; i++)
        {
            if(bitString[i] == '1')
            {
                indexes.push_back(i);
            }
        }

        for (int i = 0; i < indexes.size(); i++)
        {
            if (i % 2 == 0) a |= (1 << indexes[i]);
            else b |= (1 << indexes[i]);
        }

        printf("%d %d\n", a, b);
        
    }
    
    return 0;
}