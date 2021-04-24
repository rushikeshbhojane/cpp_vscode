#include <iostream>
#include <cmath>
using namespace std;
bool isPerfectSquare(long long  number)
{
    long double sr  = sqrt(number);
    return (sr - floor(sr)) == 0  ;
}

int main() {
    while (1)
    {
        long long SZ, P;
        long long line, column;
        string tempString;
        getline(cin, tempString);
        sscanf(tempString.c_str(), "%lld %lld", &SZ, &P);
        if (SZ == 0 && P == 0) {
            break;
        }

        long long centre = ceil(SZ*1.0/2);

        long long root = (long long)sqrt(P);
        if (root%2 && isPerfectSquare(P)) {
            line = column = (centre + root/2);
        } else {
            if (root % 2 == 0) root--; 
            long long diff = P - pow(root, 2);
            long long div = diff/(root + 1) , mod = diff%(root + 1);
            switch (div)
            {
                case 0:                    
                    line  = centre + root/2  + 1;
                    column = centre + root/2 - diff + 1;
                    break;
                
                case 1:
                    column = centre - root/2 - 1;
                    line = centre + root/2 + 1 - mod;
                    break;
                
                case 2:
                    line  = centre - root/2  - 1;
                    column = centre - root/2 + mod - 1;
                    break;
                
                case 3:
                    line = centre - root/2 - 1 + mod;
                    column = centre + root/2 + 1;
                    break;
                
            
                default:
                        line  = centre + root/2  + 1;
                        column = centre - root/2 - 1 + mod;

                    break;
            }

        }
        printf("Line = %lld, column = %lld.\n", line, column);
    }
    
    return 0;
}