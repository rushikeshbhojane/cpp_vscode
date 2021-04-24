#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    string tempInp;
    getline(cin , tempInp);
    while(t--)  {
        int perm;
        vector<int> permArr;
        string floatVal;
        getline(cin , tempInp);
        getline(cin , tempInp);
        istringstream is(tempInp);
        while (is >> perm)
        {
            permArr.push_back(perm);
        }
        getline(cin , tempInp);
        istringstream fs(tempInp);
        int iterator = 0;
        map<int, string> myMap; 
        while (fs >> floatVal)
        {
            myMap[permArr[iterator]] = floatVal;
            iterator++;
        }
        for (int i = 1; i <= iterator; i++)
        {
            cout << myMap[i] << "\n";
        }
        if ( t!=  0)
            cout << "\n";        
    }
    return 0;
}
