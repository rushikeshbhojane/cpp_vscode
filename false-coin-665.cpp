#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    string clear, first, second, tc;
    getline(cin, clear);
    while(t--)  {
        getline(cin, clear);
        getline(cin, tc);
        istringstream f(tc);
        int N, K;
        f >> N >> K;
        bool coinArray[N + 1] = {false};
        for (int i = 0; i < K; i++)
        {
            getline(cin, first);
            int count;
            istringstream fir(first);
            fir >> count;
            int tempArr[count*2], iter = 0, inp;
            while (fir >> inp)
            {
                /* code */
                tempArr[iter] = inp;
                iter++;
            }
            getline(cin, second);
            if (second == "=") {
                for (int i = 0; i < count*2; i++)
                {
                    coinArray[tempArr[i]] =  true;
                }
                
            }
            
        }

        bool isFalseCoinFound = false, isMultipleFalseCoins = false;
        int falseCoinValue = 0;

        for (int i = 1; i <= N; i++)
        {
            /* code */
            if (!coinArray[i]) {
                if (isFalseCoinFound) {
                    isMultipleFalseCoins = true;
                    break;
                }
                isFalseCoinFound = true;
                falseCoinValue = i;
            }
        }
        

        if (isFalseCoinFound && !isMultipleFalseCoins) {
            cout << falseCoinValue << "\n" ;
        } else {
            cout << 0 << "\n";
        }

        if (t != 0) 
            cout << "\n";

        
    }
    return 0;
}
