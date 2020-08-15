#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bitset>
using namespace std;
bitset<100000> arr(0);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int duplicates  = 0;
        arr.reset();
        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            if (arr[temp]) duplicates++;
            arr.set(temp);
        }
        printf("%d\n", duplicates);
    }
    
    return 0;
}