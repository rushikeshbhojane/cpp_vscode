#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bitset>
using namespace std;
int main()
{
    string line;
    while (1)
    {
        int N, M;
        getline(cin, line);
        sscanf(line.c_str(), "%d %d", &N, &M);
        if(N ==0 && M ==0) break;
        bitset<1000001> days;
        bool conflict = false;
        for (int i = 0; i < N; i++)
        {
            int start, end;
            getline(cin, line);
            sscanf(line.c_str(), "%d %d", &start, &end);
        }
        
        /* code */
    }
    
    return 0;
}