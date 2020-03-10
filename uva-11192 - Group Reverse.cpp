#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;

int main() {
    // your code goes here
    string input;
    while (getline(cin, input) && input != "0")
    {
        /* code */
        int groupLength, stringLength;
        char inputString[100];
        sscanf(input.c_str(), "%d %s", &groupLength, inputString);
        stringLength = strlen(inputString);
        for (int i = 0; i < stringLength; i+= groupLength)
        {
            reverse(inputString + i, inputString + groupLength);
        }
        cout << inputString << "\n";
    }
    
}
