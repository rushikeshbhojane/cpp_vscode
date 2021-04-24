#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
#define REP(i,a,b) for(int i = int(a); i <= int(b); i++)

char** rotate90degree(int dimensions, char** input) {
    char** rotated = new char*[dimensions];
    for (int i = 0; i < dimensions; i++)
    {
        rotated[i] = new char[dimensions];
    }
    for (int i = dimensions - 1, k = 0; i >= 0, k < dimensions; i--, k++)
    {
        for (int j = 0, l = 0; j < dimensions, l < dimensions; j++, l++)
        {
            rotated[l][k] = input[i][j];
        }
            
    }

    return rotated;
}

char** rotate180degree(int dimensions, char** input) {
    char** rotated = new char*[dimensions];
    for (int i = 0; i < dimensions; i++)
    {
        rotated[i] = new char[dimensions];
    }

    for (int i = dimensions - 1, k = 0; i >= 0, k < dimensions; i--, k++)
    {
        for (int j = dimensions - 1, l = 0; j >= 0, l < dimensions; j--, l++)
        {
            rotated[k][l] = input[i][j];
        }
            
    }
    return rotated;
    
}

char** rotate270degree(int dimensions, char** input) {
    char** rotated = new char*[dimensions];
    for (int i = 0; i < dimensions; i++)
    {
        rotated[i] = new char[dimensions];
    }

    for (int i = dimensions - 1, k = 0; i >= 0, k < dimensions; i--, k++)
    {
        for (int j = 0, l = 0; j < dimensions, l < dimensions; j++, l++)
        {
            rotated[k][l] = input[j][i];
        }
            
    }
    return rotated;    
}

bool checkIfSquaresAreEqual(int n, int lspointer1, int lspointer2, char** ss, char** ls) {
    for (int i1 = 0, i2 = lspointer1; i1 < n; i1++, i2++)
        for (int j1 = 0, j2 = lspointer2; j1 < n; j1++, j2++)
            if (ss[i1][j1] != ls[i2][j2])
                return false; 
    
    return true;
}

int main() {
    int N, n;
    string tempString;
    while (1)
    {
        getline(cin, tempString);
        sscanf(tempString.c_str(), "%d %d", &N, &n);

        if (N == 0 && n == 0) {
            break;
        }

        char**  BigSquare = new char*[N];
        REP(i,0,N-1)
        {
            BigSquare[i] = new char[N];
        }
        char** SmallSquare = new char*[n];
        REP(i,0,n-1)
        {
            SmallSquare[i] = new char[n];
        }

        REP(i,0,N-1)
        {
            getline(cin, tempString);
            char characterArray[tempString.size() + 1];
            strcpy(characterArray, tempString.c_str());
            REP(j,0,N-1)
            {
                sscanf(characterArray + j,"%c", &BigSquare[i][j]);
            }
        }

        REP(i,0,n-1)
        {
            getline(cin, tempString);
            char characterArray[tempString.size() + 1];
            strcpy(characterArray, tempString.c_str());
            REP(j,0,n-1)
            {
                sscanf(characterArray + j,"%c", &SmallSquare[i][j]);
            }
        }

        int sscount1 = 0, sscount2 = 0, sscount3 = 0, sscount4 = 0;
        char** ss90 = rotate90degree(n, SmallSquare);
        char** ss180 = rotate180degree(n, SmallSquare);
        char** ss270 = rotate270degree(n, SmallSquare);
        REP(i,0,N-n)
        {
            REP(j,0,N-n)
            {
                if(checkIfSquaresAreEqual(n, i, j, SmallSquare, BigSquare)) sscount1++;
                if(checkIfSquaresAreEqual(n, i, j, ss90, BigSquare)) sscount2++;
                if(checkIfSquaresAreEqual(n, i, j, ss180, BigSquare)) sscount3++;
                if(checkIfSquaresAreEqual(n, i, j, ss270, BigSquare)) sscount4++;
            }
        }
        printf("%d %d %d %d\n", sscount1, sscount2, sscount3, sscount4);
    }
    
    return 0;
}