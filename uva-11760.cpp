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
    int counter = 0;
    while (1)
    {
        counter++;
        getline(cin, line);
        int R, C , N;
        sscanf(line.c_str(), "%d %d %d", &R ,&C, &N);

        if (R == 0 && C == 0 && N == 0)
        {
            break;
        }

        bitset<10001> rows(0);
        bitset<10001> cols(0);
        for (int i = 0; i < N; i++)
        {
            getline(cin, line);
            int r, c;
            sscanf(line.c_str(), "%d %d", &r ,&c);
            rows[r] = 1;
            cols[c] = 1;
        }

        getline(cin, line);
        int arifR, arifC;
        sscanf(line.c_str(), "%d %d", &arifR, &arifC);

        bool isPossible = false;

        if (!rows[arifR] && !cols[arifC])
        {
            isPossible = true;
        }
        else if (arifR-1 >= 0 && (!rows[arifR-1] && !cols[arifC]))
        {
            isPossible = true;
        }
        else if (arifC+1 < C && (!rows[arifR] && !cols[arifC+1]))
        {
            isPossible = true;
        }
        else if (arifR+1 < R && (!rows[arifR+1] && !cols[arifC]))
        {
            isPossible = true;
        }
        else if (arifC-1 >=0 && (!rows[arifR] && !cols[arifC-1]))
        {
            isPossible = true;
        }

        printf("Case %d: %s\n", counter, isPossible ? "Escaped again! More 2D grid problems!" : "Party time! Let’s find a restaurant!");
    }
    
    return 0;
}