#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while(t--)  {
        string s;
        cin >> s;
        cout << *s.c_str();        
    }
    return 0;
}
