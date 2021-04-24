#include <iostream>
#include <sstream>
using namespace std;
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


char** rotateVertical(int dimensions, char** input) {
   char** rotated = new char*[dimensions];
   for (int i = 0; i < dimensions; i++)
   {
       rotated[i] = new char[dimensions];
   }
   for (int i = 0; i < dimensions; i++)
   {
       for (int j = 0; j < dimensions; j++)
       {
           rotated[dimensions - i - 1][j] = input[i][j];
       }
       
   }

   return rotated;
   
}

bool checkIfEqual(int dimensions, char** input , char** output) {
    for (int i = 0; i < dimensions; i++)
    {
        for (int j = 0; j < dimensions; j++)
        {
            if (input[i][j] != output[i][j]) {
                return false;
            }
        }
        
    }
    
    return true;
}


int main() {
    int dimensions;
    int patternNo = 0;
    while (cin >> dimensions) {
        patternNo++;
        string ts;
        getline(cin, ts);
        char** input = new char*[dimensions];
        char** output = new char*[dimensions];

        for (int i = 0; i < dimensions; i++)
        {
            input[i] = new char[dimensions];
            output[i] = new char[dimensions];
        }
        


        for (int i = 0; i < dimensions; i++)
        {
            string s;
            getline(cin, s);  
            sscanf(s.c_str(), "%s %s", input[i], output[i]);
        }


        if (checkIfEqual(dimensions, input, output)) {
            printf("Pattern %d was preserved.\n", patternNo);
        } else if (checkIfEqual(dimensions, rotate90degree(dimensions, input), output)) {
            printf("Pattern %d was rotated 90 degrees.\n", patternNo);
        } else if (checkIfEqual(dimensions, rotate180degree(dimensions, input), output)) {
            printf("Pattern %d was rotated 180 degrees.\n", patternNo);
        } else if (checkIfEqual(dimensions, rotate270degree(dimensions, input), output)) {
            printf("Pattern %d was rotated 270 degrees.\n", patternNo);
        }else {
            char** verticallyReflectedPattern =  rotateVertical(dimensions, input);
            if (checkIfEqual(dimensions, verticallyReflectedPattern, output))
            {
                printf("Pattern %d was reflected vertically.\n", patternNo);
            }
            else if (checkIfEqual(dimensions, rotate90degree(dimensions, verticallyReflectedPattern), output))
            {
                printf("Pattern %d was reflected vertically and rotated 90 degrees.\n", patternNo);
            }
            else if (checkIfEqual(dimensions, rotate180degree(dimensions, verticallyReflectedPattern), output))
            {
                printf("Pattern %d was reflected vertically and rotated 180 degrees.\n", patternNo);
            }
            else if (checkIfEqual(dimensions, rotate270degree(dimensions, verticallyReflectedPattern), output))
            {
                printf("Pattern %d was reflected vertically and rotated 270 degrees.\n", patternNo);
            }
            else
            {
                printf("Pattern %d was improperly transformed.\n", patternNo);
            }
            
        }

    }
    return 0;
}