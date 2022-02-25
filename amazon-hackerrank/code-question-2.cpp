#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'decodeString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER numberOfRows
 *  2. STRING encodedString
 */

string decodeString(int numberOfRows, string encodedString) {
    string soln = "";
    int numberOfColumns = encodedString.size() / numberOfRows;
    char encodedMatrix[numberOfRows][numberOfColumns];
    int counter = 0;
    
    for (int r = 0; r < numberOfRows; r++) {
        for (int c = 0; c < numberOfColumns; c++) {
            encodedMatrix[r][c] = encodedString[counter++];
        }
    }
    
    for (int c = 0; c < numberOfColumns ; c++) {
        int columnNumber = c, rowNumber = 0;
        while (columnNumber < numberOfColumns && rowNumber < numberOfRows) {
            if (encodedMatrix[rowNumber][columnNumber] == '_') {
                soln += ' ';
            } else {
                soln += encodedMatrix[rowNumber][columnNumber];
            }
            columnNumber++; rowNumber++;
        }
    }
    
    ltrim(soln);
    return soln;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string numberOfRows_temp;
    getline(cin, numberOfRows_temp);

    int numberOfRows = stoi(ltrim(rtrim(numberOfRows_temp)));

    string encodedString;
    getline(cin, encodedString);

    string result = decodeString(numberOfRows, encodedString);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}