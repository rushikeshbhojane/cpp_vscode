#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    string line;
    while (getline(cin, line))
    {
        if (line == "#") break;
        int length = line.length();

        bool breakInside = false;
        for (int i = length-2; i >= 0; i--)
        {
            if (line[i] < line[i+1])
            {
                /* code */
                sort(line.begin() + i  + 1 , line.end());
                for (int j = i+1; j < length; j++)
                {
                    if (line[j] > line[i]) {
                        breakInside = true;
                        swap(line[i], line[j]);
                        break;
                    }
                }
                
            }
            if(breakInside) break; 
            
        }     

        if (breakInside)
        {
            printf("%s\n", line.c_str());
        }
        else
        {
            printf("No Successor\n");
        }
        
    }
    
    return 0;
}