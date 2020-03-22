#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++ )
int main() {
    // your code goes here
    int t, tcCount = 0;
    cin >> t;
    bool sumSolvedBy1[10005] = {false},
            sumSolvedBy2[10005] = {false},
            sumSolvedBy3[10005] = {false},
            foundAlready[10005] = {false};
    while(t--)  {
        memset(sumSolvedBy1, false, 10005);
        memset(sumSolvedBy2, false, 10005);
        memset(sumSolvedBy3, false, 10005);
        tcCount++;
        int solvedCount1, solvedCount2, solvedCount3;
        scanf("%d", &solvedCount1);
        int solvedCount1Array[solvedCount1];
        REP(i, 0, solvedCount1 - 1) {
            scanf("%d", &solvedCount1Array[i]);
            sumSolvedBy1[solvedCount1Array[i]] = true; 
        }

        scanf("%d", &solvedCount2);
        int solvedCount2Array[solvedCount2];
        REP(i, 0, solvedCount2 - 1) {
            scanf("%d", &solvedCount2Array[i]);
            sumSolvedBy2[solvedCount2Array[i]] = true; 
        }
        scanf("%d", &solvedCount3);
        int solvedCount3Array[solvedCount3];         
        REP(i, 0, solvedCount3 - 1) {
            scanf("%d", &solvedCount3Array[i]);
            sumSolvedBy3[solvedCount3Array[i]] = true; 
        }

        int countOfOnly1 = 0, countOfOnly2 = 0, countOfOnly3 = 0;

        memset(foundAlready, false, 10005);
        for (int i: solvedCount1Array)
        {
           if (!foundAlready[i] && sumSolvedBy1[i] 
                    && !sumSolvedBy2[i] && !sumSolvedBy3[i]) {
               foundAlready[i] = true;
               countOfOnly1++;
           } 
        }

        memset(foundAlready, false, 10005);
        for (int i: solvedCount2Array)
        {
           if (!foundAlready[i] && sumSolvedBy2[i]
                    && !sumSolvedBy1[i] && !sumSolvedBy3[i]) {
               foundAlready[i] = true;
               countOfOnly2++;
           } 
        }

        memset(foundAlready, false, 10005);
        for (int i: solvedCount3Array)
        {
           if (!foundAlready[i] && sumSolvedBy3[i]
                    && !sumSolvedBy2[i] && !sumSolvedBy1[i]) {
               foundAlready[i] = true;
               countOfOnly3++;
           } 
        }
        
        printf("Case #%d:\n", tcCount);
        if (countOfOnly1 >= max(countOfOnly2, countOfOnly3)) {
            memset(foundAlready, false, 10005);
            sort(solvedCount1Array, solvedCount1Array + solvedCount1);
            cout << 1 << " " <<  countOfOnly1;
            if (countOfOnly1 != 0) cout  << " "; 
            int lc  = 0;
            for (int i: solvedCount1Array)
            {
                if (!foundAlready[i] &&
                        !sumSolvedBy2[i] && !sumSolvedBy3[i]) {
                    foundAlready[i] = true;
                    lc++;
                    cout << i;
                    if (lc != countOfOnly1) {
                        cout << " ";
                    }
                }
            }
            cout << "\n";
        }

        if (countOfOnly2 >= max(countOfOnly1, countOfOnly3)) {
            memset(foundAlready, false, 10005);
            sort(solvedCount2Array, solvedCount2Array + solvedCount2);
            cout << 2 << " " <<  countOfOnly2;
            if (countOfOnly2 != 0) cout  << " "; 
            int lc = 0;
            for (int i: solvedCount2Array)
            {
                if (!foundAlready[i] &&
                        !sumSolvedBy1[i] && !sumSolvedBy3[i]) {
                    foundAlready[i] = true;
                    lc++;
                    cout << i;
                    if (lc != countOfOnly2) {
                        cout << " ";
                    }
                }
            }
            cout << "\n";
        }

        if (countOfOnly3 >= max(countOfOnly1, countOfOnly2)) {
            memset(foundAlready, false, 10005);
            sort(solvedCount3Array, solvedCount3Array + solvedCount3);
            cout << 3 << " " <<   countOfOnly3;
            if (countOfOnly3 != 0) cout  << " "; 
            int lc  = 0;
            for (int i: solvedCount3Array)
            {
                if (!foundAlready[i] &&
                        !sumSolvedBy1[i] && !sumSolvedBy2[i]) {
                    foundAlready[i] = true;
                    lc++;
                    cout << i;       
                    if (lc != countOfOnly3) {
                        cout << " ";
                    }
                } 
            }
            cout << "\n";
        }

    }
    return 0;
}
