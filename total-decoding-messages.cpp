#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while(t--)  {
        int n;
        string s;
        cin >> n >>  s;

        int count[n + 1] = {1, 1};

        if(s[0]=='0')   
            goto standatdop; 
        for (int i = 1; i <= n; i++)
        {
            /* code */
            if (s[i - 1] > '0') {
                count[i] = count[i - 1];
            }

            if (s[i-2] == '1' ||  
              (s[i-2] == '2' && s[i-1] < '7') ) 
            count[i] += count[i-2]; 
        }
        
        standatdop:
        cout << count[n] << "\n";

    }
    return 0;
}
