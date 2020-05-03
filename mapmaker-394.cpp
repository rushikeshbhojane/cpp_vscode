#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;
class Problem
{
private:
    /* data */
    int baseAddress, sizeOfElement, dimensions, C0;
    vector<int> bounds, boundsModified, leftBounds;
public:
    void enter() {
        cin >> baseAddress >> sizeOfElement >> dimensions;
        for (int i = 0; i < dimensions; i++)
        {
            int lb, ub;
            cin >> lb >> ub;
            bounds.push_back(ub - lb);
            leftBounds.push_back(lb);
        }
        int initial = sizeOfElement;
        boundsModified.push_back(sizeOfElement);
        for (int i = dimensions - 1; i > 0; i--)
        {
            /* code */
            sizeOfElement  = sizeOfElement * (bounds[i] + 1);
            boundsModified.push_back(sizeOfElement);
        }
        reverse(boundsModified.begin(), boundsModified.end());
        C0 = baseAddress;
        for (int i = 0; i < dimensions; i++) {
            C0 -= boundsModified[i]*leftBounds[i];
        }
    }
    int solve(vector<int> dimensionIndex) {
        int address = C0;
        for (int i = 0; i < dimensions; i++)
        {
            address += boundsModified[i]*dimensionIndex[i];
        }
        return address;
    }

    Problem(/* args */) {}
    ~Problem() {}
};
int main() {
    // your code goes here
    int N, R;
    cin >> N >> R;
    map <string, Problem*> problemMap; 
    for (int i = 0; i < N; i++)
    {
        /* code */
        string name;
        cin >> name;
        Problem *p = new Problem();
        p -> enter();
        problemMap[name] = p;
    }
    string temp;
    getline(cin, temp);
    for (int i = 0; i < R; i++)
    {
        /* code */
        string input, problemName;
        int d;
        vector<int> dimensionsIndex;
        getline(cin, input);
        stringstream ss(input);
        ss >> problemName;
        while (ss >> d)
        {
            dimensionsIndex.push_back(d);
        }
        int soln  = problemMap[problemName] -> solve(dimensionsIndex);
        string solnOp = problemName + "[";
        int dimensionsIndexSize = dimensionsIndex.size();
        for (int j = 0; j < dimensionsIndexSize; j++)
        {
            solnOp += to_string(dimensionsIndex[j]);
            if (j < dimensionsIndexSize -1 ) {
                solnOp += ", ";
            }
        }
        solnOp += "] = ";
        solnOp += to_string(soln);
        solnOp += "\n";
        cout << solnOp;
    }
    
    
    return 0;
}
