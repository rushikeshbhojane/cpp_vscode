#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N, Q;
        cin >> N >> Q;
        string s;
        cin >> s;
        int countChars[26] = {0};

        for (char c: s)
        {
            ++countChars[c - 'a'];
        }

        for (int i = 0; i < Q; i++)
        {
            int C;
            cin >> C;
            int pending = 0;

            for (int j = 0; j < 26; j++)
            {
                pending += (countChars[j] > C ? countChars[j] - C : 0);
            }

            cout << pending << "\n";
            
        }
        
        
    }
    
}