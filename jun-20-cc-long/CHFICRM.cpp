#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr;
        for (int i = 0; i < N; i++)
        {
            int inp;
            cin >> inp;
            arr.push_back(inp);
        }

        int cnt5 = 0, cnt10 = 0, cnt15 = 0;
        bool isPossible  = true;
        for (int i = 0; i < N; i++)
        {
            switch (arr[i])
            {
                case 10:
                        if (cnt5) cnt5--;
                        else isPossible = false; 
                        cnt10++;
                    break;
                
                case 15:
                        if (cnt10) cnt10--;
                        else if (cnt5 >= 2) cnt5 -= 2;
                        else isPossible = false;
                        cnt15++; 
                    break;
                
                default:
                        cnt5++;
                    break;
            }
            if (!isPossible) {
                break;
            }
        }

        if (isPossible) printf("YES\n");
        else printf("NO\n");
        
    }
    
    return 0;
}