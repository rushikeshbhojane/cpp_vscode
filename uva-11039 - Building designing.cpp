#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
bool absSort(int n1, int n2) {
    if (abs(n1) > abs(n2)) {
        return true;
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        vector<int> Numbers;

        for (int i = 0; i < N; i++)
        {
            int n;
            cin >> n;
            Numbers.push_back(n);            
        }
        
        sort(Numbers.begin(), Numbers.end(), absSort);



    }
    
    return 0;
}