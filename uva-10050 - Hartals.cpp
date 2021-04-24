#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while(t--)  {
        int N, P;
        cin >> N >> P;
        bool simulation[N + 1] = {false};
        int hartalParameter[P];
        for (int i = 0; i < P; i++)
        {
            cin >> hartalParameter[i];
        }
        for (int i: hartalParameter)
        {
            for (int j = i; j <= N; j += i)
            {
                simulation[j] = true;
            }
            
        }
        int dayslost = 0;
        for (int i = 1; i < N + 1; i++)
        {
            if (simulation[i] && !(i % 7  == 0 || i % 7 == 6)) {
                dayslost++;
            } 
        }
        
        cout << dayslost << "\n";        
    }
    return 0;
}
