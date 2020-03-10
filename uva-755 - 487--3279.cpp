#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <regex>
using namespace std;

int main() {
    // your code goes here
    string testcases;
    int t;
    getline(cin, testcases);
    sscanf(testcases.c_str(),"%d",&t);
    std::regex re_ABC("A|B|C");
    std::regex re_DEF("D|E|F");
    std::regex re_GHI("G|H|I");
    std::regex re_JKL("J|K|L");
    std::regex re_MNO("M|N|O");
    std::regex re_PRS("P|R|S");
    std::regex re_TUV("T|U|V");
    std::regex re_WXY("W|X|Y");
    std::regex re_hyphen("-");
    while (t--)
    {
        string inp, numberString;
        getline(cin, inp);
        int numbers;
        getline(cin, numberString);
        sscanf(numberString.c_str(), "%d", &numbers);
        map<string, int> count;
        for (int i = 0; i < numbers; i++)
        {
            getline(cin, numberString);
            string tempString = "";
            int length = 0;
            for (char c: numberString)
            {
                switch (c)
                {
                case 'A':
                case 'B':
                case 'C':
                    length++;
                    tempString += '2';
                    if (length == 3)   tempString += '-';
                    break;
                 
                case 'D':
                case 'E':
                case 'F':
                    length++;
                    tempString += '3';
                    if (length == 3)   tempString += '-';
                    break;

                case 'G':
                case 'H':
                case 'I':
                    length++;
                    tempString += '4';
                    if (length == 3)   tempString += '-';
                    break;

                case 'J':
                case 'K':
                case 'L':
                    length++;
                    tempString += '5';
                    if (length == 3)   tempString += '-';
                    break;

                case 'M':
                case 'N':
                case 'O':
                    length++;
                    tempString += '6';
                    if (length == 3)   tempString += '-';
                    break;

                case 'P':
                case 'R':
                case 'S':
                    length++;
                    tempString += '7';
                    if (length == 3)   tempString += '-';
                    break;

                case 'T':
                case 'U':
                case 'V':
                    length++;
                    tempString += '8';
                    if (length == 3)   tempString += '-';
                    break;

                case 'W':
                case 'X':
                case 'Y':
                    length++;
                    tempString += '9';
                    if (length == 3)   tempString += '-';
                    break;

                case 'Q':
                case 'Z':
                    length++;
                    tempString += c;
                    if (length == 3)   tempString += '-';
                    break;

                default:
                    if  (c != '-') {
                        length++;
                        tempString += c;
                        if (length == 3)   tempString += '-';
                    }
                    break;
                }
            }
            if (count.find(tempString) == count.end()) {
                count[tempString] = 1;
            } else {
                count[tempString]++;
            }
            }
        bool multipleFlag = false;
        for (map<string, int>::iterator i = count.begin()
                ; i != count.end()
                ; i++)
        {
            if (i -> second > 1) {
                cout << i -> first << " " << i -> second << "\n";
                multipleFlag = true;
            }
        }

        if (!multipleFlag) {
            cout << "No duplicates." << "\n";
        }

        if (t != 0) {
            cout << "\n";
        }
    }
    
    return 0;
}
