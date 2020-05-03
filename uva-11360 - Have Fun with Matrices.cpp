#include <iostream>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
void singleIntScan(int& input) {
    string tempString;
    getline(cin, tempString);
    sscanf(tempString.c_str(), "%d", &input);
}

void inc(int incNo, int N, vector<vector<int> >& Matrix) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Matrix[i][j] = (Matrix[i][j]+incNo);
            if (Matrix[i][j] == -1) {
                Matrix[i][j] = 9;
            }

            Matrix[i][j] = Matrix[i][j]%10;
        }
        
    }
    
}

void transpose(int N, vector<vector<int> >& Matrix) {
    vector<vector<int> >temp(N, vector<int> (N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[i][j] = Matrix[j][i];
        
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Matrix[i][j] = temp[i][j];

}

void row(int row1, int row2, int N, vector<vector<int> >& Matrix) {
    vector<int> temp(Matrix[row1]);
    for (int i = 0; i < N; i++)
        Matrix[row1][i] = Matrix[row2][i];

    for (int i = 0; i < N; i++)
        Matrix[row2][i] = temp[i];        
}


void col(int col1, int col2, int N, vector<vector<int> >& Matrix) {
    vector<int> temp;
    for (int i = 0; i < N; i++)
    {
        temp.push_back(Matrix[i][col1]);
    }
    
    for (int i = 0; i < N; i++)
        Matrix[i][col1] = Matrix[i][col2];

    for (int i = 0; i < N; i++)
        Matrix[i][col2] = temp[i];        
}

void printMatrix(int caseNo, int N, vector<vector<int> > Matrix)
{
        printf("Case #%d\n", caseNo);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d", Matrix[i][j]);
            }
            printf("\n");
        }

}
void updateDisplayString(int N, string& displayString, vector<vector<int>  > Matrix) {
        displayString = "";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                displayString += '0' + Matrix[i][j];
            }
            displayString += "\n";
        }

}
int main() {
    int t;
    string tempString, displayString = "";
    singleIntScan(t);
    for (int count = 1; count <= t; count++)
    {
        int N, M;
        singleIntScan(N);
        vector<vector<int> > Matrix(N, vector<int> (N, 0));
        for (int i = 0; i < N; i++)
        {
            getline(cin, tempString);
            char cstring[tempString.size() + 1];
            strcpy(cstring, tempString.c_str());
            for (int j = 0; j < N; j++)
            {
                char c;
                sscanf(cstring + j, "%c", &c);
                Matrix[i][j] = c - '0';
            }
            
        }

        singleIntScan(M);


        for (int i = 0; i < M; i++)
        {
            getline(cin, tempString);
            char cstring[tempString.size() + 1];
            strcpy(cstring, tempString.c_str());
            char* token = strtok(cstring, " ");
            if (strcmp(token, "row") == 0) {
                token = strtok(NULL, " ");
                int row1 = atoi(token);
                token = strtok(NULL, " ");
                int row2 = atoi(token);
                row(row1-1, row2-1, N, Matrix);
            } else if (strcmp(token, "col") == 0) {
                token = strtok(NULL, " ");
                int col1 = atoi(token);
                token = strtok(NULL, " ");
                int col2 = atoi(token);
                col(col1-1, col2-1, N, Matrix);

            } else if (strcmp(token, "inc") == 0) {
                inc(1, N, Matrix);
            } else if (strcmp(token, "dec") == 0) {
                inc(-1, N, Matrix);
            } else if (strcmp(token, "transpose") == 0) {
                transpose(N, Matrix);
            }
            updateDisplayString(N, displayString, Matrix);
        }
        
        printMatrix(count, N, Matrix);
        printf("\n");          
        
    }
    
    return 0;
}