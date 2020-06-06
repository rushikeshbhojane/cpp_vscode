#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
pair<int, int> shrinkMatrix(vector<vector<char> >& matrix, int N)
{
    int cols  = N, rows = N;
    int rowTop = 0, rowBottom = N-1, colLeft  = 0, colRight = N - 1;
    int i, j;
    cout << matrix[0][0] <<  " " <<  '*' << " " <<  ( matrix[0][0] == '*') <<  "\n";
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (matrix[i][j] == '*') goto break1;

    break1:
    rowTop = i;

    for (i = N-1; i >= 0; i--)
        for (j = N-1; j >= 0; j--)
            if (matrix[i][j] == '*') goto break2;

    break2:
    rowBottom = i;


    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (matrix[j][i] == '*') goto break3;

    break3:
    colLeft = i;

    for (i = N-1; i >= 0; i--)
        for (j = N-1; j >= 0; j--)
            if (matrix[j][i] == '*') goto break4;
    
    break4:
    colRight = i;

    if(rowTop > 0) matrix.erase(matrix.begin(), matrix.begin() + rowTop);

    rows -= rowTop;

    for (int i = N-1; i > rowBottom; i--)
    {
        matrix.pop_back();
        rows--;
    }
        
    if (colLeft > 0) {
        for (i = 0; i < rows; i++)
            matrix[i].erase(matrix[i].begin(), matrix[i].begin()  + colLeft);
        
        cols -= colLeft;
    }

    for (int i = N-1; i > colRight; i--)
    {
        for (int j = 0; j < rows; j++)
        {
            matrix[j].pop_back();
        }
        cols--;
    }
    
    return make_pair(rows, cols);
}

pair<int, int> getLeftTopMostEmpty
        (vector<vector<char> >& largeStringMatrix, 
            vector<vector<bool> >& largeStringMatrixBool, int N, int M)
{
    int rowIndex, colIndex;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (largeStringMatrix[j][i] == '*' && !largeStringMatrixBool[j][i])
                return make_pair(j, i);
        }
        
    }

    return make_pair(-1, -1);
    
}

bool compareLargeWithSmallForMatch(int row,int column, int rowIndex, int colIndex,
                                    vector<vector<char> >& largeStringMatrix, 
                                    vector<vector<bool> >& largeStringMatrixBool,
                                    vector<vector<char> >& smallStringMatrix)
{
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (!largeStringMatrixBool[rowIndex + i][colIndex + j]
                        && smallStringMatrix[i][j] == largeStringMatrix[rowIndex + i][colIndex + j])
                {
                    largeStringMatrixBool[rowIndex + i][colIndex + j] = true;
                }
                else if (smallStringMatrix[i][j] == '*')
                {
                    return false;
                }
                
            }
            
        }

        return true;
        
}


bool matchAndFill
        (vector<vector<char> >& largeStringMatrix, 
            vector<vector<bool> >& largeStringMatrixBool, int N,
            vector<vector<char> >& smallStringMatrix, int row, int column)
        {


                vector<vector<bool> > ebm = vector<vector<bool> >(row, vector<bool>(column, 0));
                pair<int, int> slfe = getLeftTopMostEmpty(smallStringMatrix, ebm, row, column);
                pair<int, int> llfe = getLeftTopMostEmpty(largeStringMatrix, largeStringMatrixBool, N, N);
                if (llfe.first == -1 && llfe.second == -1) return false; 
                llfe.first -= slfe.first;
                llfe.second -= slfe.second;

                if (!compareLargeWithSmallForMatch(row,column, llfe.first, llfe.second,
                                                    largeStringMatrix, 
                                                    largeStringMatrixBool,
                                                    smallStringMatrix))
                {
                        return false; 
                }


                llfe = getLeftTopMostEmpty(largeStringMatrix, largeStringMatrixBool, N, N);
                if (llfe.first == -1 && llfe.second == -1) return false; 
                llfe.first -= slfe.first;
                llfe.second -= slfe.second;

                if (!compareLargeWithSmallForMatch(row,column, llfe.first, llfe.second,
                                                    largeStringMatrix, 
                                                    largeStringMatrixBool,
                                                    smallStringMatrix))
                {
                        return false; 
                }

                return true;
        }

int main()
{
    string tempString;
    int N, M, rows, cols;
    while (1)
    {
        getline(cin, tempString);
        sscanf(tempString.c_str(), "%d %d", &N, &M);
        bool isPossible  = true;

        if (N == 0 && M == 0)
        {
            break;
        }

        vector<vector<char> > largeStringMatrix(N, vector<char>(N));
        vector<vector<bool> > largeStringMatrixBool(N, vector<bool>(N, 0));
        
        vector<vector<char> > smallStringMatrix(M, vector<char>(M));
        
        for (int i = 0; i < N; i++)
        {
            getline(cin, tempString);
            copy(tempString.begin(), tempString.end(), largeStringMatrix[i].begin());
        }

        for (int i = 0; i < M; i++)
        {
            getline(cin, tempString);
            copy(tempString.begin(), tempString.end(), smallStringMatrix[i].begin());
        }


        pair<int, int> shrinkedSize = shrinkMatrix(smallStringMatrix, M);
        rows = shrinkedSize.first;
        cols = shrinkedSize.second;
    
        isPossible = matchAndFill
                        (largeStringMatrix, 
                            largeStringMatrixBool, N,
                            smallStringMatrix, rows, cols);

        printf("%d\n", isPossible ? 1 : 0);
    }
    
    
    return 0;
}