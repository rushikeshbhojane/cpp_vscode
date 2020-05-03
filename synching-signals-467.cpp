#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++) 
using namespace std;

int main() {
    // your code goes here
    string input;
    int caseNo = 0;
    while (getline(cin, input))
    {
        caseNo++;
        int v[7200] = {0}, time = 0xFFFFFFF, mx = 0xFFFFFFF;
        int totalCount = 0;
        int cycleTime;
        stringstream ss(input);
        while (ss >> cycleTime)
        {
            mx = min(mx, cycleTime);
            totalCount++;
            int baseTime = -1 * cycleTime;
            while (baseTime <= 3600)
            {
                baseTime += cycleTime;
                for (int i = baseTime + 1, j = 0; j < cycleTime -  5; i++, j++)
                {
                    v[i]++;
                }   
                baseTime += cycleTime;
            }
        }

        REP(i,mx,3601) {
            if (v[i] == totalCount) {
                time = i-1;
                break;
            }
        }
        printf("Set %d ", caseNo);
        if (time <= 3600) {
            printf("synchs again at %d minute(s) and %d second(s) after all turning green.\n",time/60, time%60);
        } else {
            printf("is unable to synch after one hour.\n");
        }
        
    }
    
    return 0;
}
