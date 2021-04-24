#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i,a,b) for(int i = int(a); i <= int(b); i++)
#define REPN(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;

int main() {
    // your code goes here
    int n;
    while (cin >> n && n != 0)
    {
        cin.clear();
        int stops[n];
        REP(i, 0, n-1)
        {
            scanf("%d", &stops[i]);
        }
        sort(stops, stops + n);
        int reached_point = 0;
        bool possible = true;
        REP(i, 0, n-1) {
            if (reached_point < stops[i]) {
                possible = false;
                goto printAnswer;
            }
            reached_point = stops[i] + 200;
        }
        if (reached_point < 1422)
        {
            possible = false;
            goto printAnswer;
            break;
        } else {
            if (2 * (1422 - stops[n-1]) > 200) {
                possible = false;
                goto printAnswer;
                break;
            } else {
                reached_point = stops[n-1];
            }
        }

        REPN(i, n-1, 0) {
            if (reached_point > stops[i]) {
                possible = false;
                goto printAnswer;
                break;
            }
            reached_point = stops[i] - 200;
        }

        printAnswer:
        possible ? printf("POSSIBLE\n") : printf("IMPOSSIBLE\n");
    }
    
    return 0;
}
