#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
struct Node {
    int sizeOfTriangle = 0;
    vector<int> sides = {};
};

/* utuility function */
int getMid(int start, int end) { return (start + end)/2; }  

int GetPerimeter(int x, int y, int z)
{
    if ((x + y >= z)
        && (y + z >= x)
        && (x + z >= y))
    {
        return x + y + z;
    }
    return 0;
}

int getMaxPerimeterFromArray(vector<int>& sides)
{
    int maxValue = 0;
    int arrSize = sides.size();
    if(arrSize < 3) return maxValue;

    for (int i = 2; i < arrSize; i++)
    {
        maxValue = max(maxValue,
                    GetPerimeter(
                        sides[i-2],
                        sides[i-1],
                        sides[i]
                    )
                );
    }
    return maxValue;
    
}

void merge(vector<int> &parentArray, vector<int> &left, vector<int> &right)
{
    int leftSize = left.size(), rightSize = right.size(); 
    parentArray.clear();

    int leftCounter = 0, rightCounter = 0;

    for (; leftCounter < leftSize && rightCounter < rightSize;)
    {
        if (left[leftCounter] < right[rightCounter])
        {
            parentArray.push_back(left[leftCounter++]);
        }
        else
        {
            parentArray.push_back(right[rightCounter++]);
        }
    }

    while (leftCounter < leftSize) parentArray.push_back(left[leftCounter++]);
    while (rightCounter < rightSize) parentArray.push_back(right[rightCounter++]);

    if (leftSize + rightSize < 50) return;

    int breakpoint = 2;
    bool isBreakpointFound = false;
    int i = breakpoint;
    for (; i < leftSize + rightSize; i++)
    {
        if (GetPerimeter(parentArray[i-2],
                        parentArray[i-1],
                        parentArray[i])) {
                isBreakpointFound = true;
                breakpoint++;
        }
    }

    if(isBreakpointFound)
    {
        parentArray.erase(parentArray.begin(), parentArray.begin() + (breakpoint - 3));
    }
    
}
vector<int> buildSegTreeUtil(int sides[], int segmentStart, int segmentEnd, Node** segmentTree, int segmentIndex)
{
    if (segmentStart == segmentEnd)
    {
        segmentTree[segmentIndex] -> sizeOfTriangle = 0;
        segmentTree[segmentIndex] -> sides.push_back(sides[segmentStart]);
        return segmentTree[segmentIndex] -> sides;
    }

    int mid = getMid(segmentStart, segmentEnd);

    vector<int> left = buildSegTreeUtil(sides, segmentStart, mid, segmentTree, (segmentIndex << 1) + 1);
    vector<int> right = buildSegTreeUtil(sides, mid + 1, segmentEnd, segmentTree, (segmentIndex << 1) + 2);

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    merge(segmentTree[segmentIndex] -> sides, left, right);

    return segmentTree[segmentIndex] -> sides;
}

void buildSegTree(int N, int sides[], int sizeCap, Node* segmentTree[])
{    
    buildSegTreeUtil(sides, 0, N-1, segmentTree, 0);
}

vector<int> getMaxPerimeterUtil(Node* segmentTree[], int segmentStart, int segmentEnd, int left, int right, int segmentIndex)
{
    if (segmentStart > right || segmentEnd < left) return {};

    if (left <= segmentStart && right >= segmentEnd) return segmentTree[segmentIndex] -> sides;

    int mid = getMid(segmentStart, segmentEnd);

    vector<int> leftArray = getMaxPerimeterUtil(segmentTree, segmentStart, mid, left, right, (segmentIndex << 1) + 1);
    vector<int> rightArray = getMaxPerimeterUtil(segmentTree, mid + 1, segmentEnd, left, right, (segmentIndex << 1) + 2);

    sort(leftArray.begin(), leftArray.end());
    sort(rightArray.begin(), rightArray.end());

    merge(segmentTree[segmentIndex] -> sides, leftArray, rightArray);

    return segmentTree[segmentIndex] -> sides;
}

int getMaxPerimeter(Node* segmentTree[], int N, int left,int right)
{
    vector<int> sides = getMaxPerimeterUtil(segmentTree, 0, N-1, left, right, 0);
    return getMaxPerimeterFromArray(sides);
}


vector<int> updateArrayUtil(int sides[], int segmentStart, int segmentEnd, Node** segmentTree, int segmentIndex, int position, int value)
{
    if (segmentStart > position || segmentEnd < position) return segmentTree[segmentIndex] -> sides;
    
    segmentTree[segmentIndex] -> sides.clear();
    if (segmentStart == segmentEnd)
    {
        segmentTree[segmentIndex] -> sizeOfTriangle = 0;
        segmentTree[segmentIndex] -> sides.push_back(sides[segmentStart]);
        return segmentTree[segmentIndex] -> sides;
    }

    int mid = getMid(segmentStart, segmentEnd);

    vector<int> left = updateArrayUtil(sides, segmentStart, mid, segmentTree, (segmentIndex << 1) + 1, position, value);
    vector<int> right = updateArrayUtil(sides, mid + 1, segmentEnd, segmentTree, (segmentIndex << 1) + 2, position, value);

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    merge(segmentTree[segmentIndex] -> sides, left, right);

    return segmentTree[segmentIndex] -> sides;
}

void updateArray(int N, int sides[], Node* segmentTree[],int position, int value)
{
    sides[position] = value;
    updateArrayUtil(sides, 0, N - 1, segmentTree, 0, position, value);
}

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    int sides[N];

    for (int i = 0; i < N; i++) scanf("%d", &sides[i]);

    int sizeCap = 2*(1 << (int)ceil(log2(N)))  - 1;
    Node* segmentTree[sizeCap];

    for (int i = 0; i < sizeCap; i++)
    {
        segmentTree[i] = new Node();
        segmentTree[i]->sides.clear();
    }
    buildSegTree(N, sides, sizeCap, segmentTree);
    // cout << "abcd";
    for (int i = 0; i < Q; i++)
    {
        int qType, arg1, arg2;
        scanf("%d %d %d", &qType, &arg1, &arg2);

        if (qType == 1)
        {
            updateArray(N, sides, segmentTree, arg1 - 1 , arg2);
        }
        else if (qType == 2)
        {
            printf("%d\n", getMaxPerimeter(segmentTree, N, arg1-1, arg2-1));
        }
    }
    
    return 0;
}