/* https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
Let us consider the following problem to understand Segment Trees.

We have an array arr[0 . . . n-1]. We should be able to
1 Find the sum of elements from index l to r where 0 <= l <= r <= n-1

2 Change value of a specified element of the array to a new value x. We need to do arr[i] = x where 0 <= i <= n-1. */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/* utuility function */
int getMid(int start, int end) { return (start + end)/2; }  

/* COnstruction of Segment Tree */
int constructSTUtil(int baseArr[], int segmentStart, int segmentEnd, int* segmentTree, int segmentIndex)
{
    if (segmentStart == segmentEnd)
    {
        segmentTree[segmentIndex] = baseArr[segmentStart];
        return baseArr[segmentStart];
    }

    int mid = getMid(segmentStart, segmentEnd);
    segmentTree[segmentIndex] = constructSTUtil(baseArr, segmentStart, mid, segmentTree, (segmentIndex << 1) + 1)
                                + constructSTUtil(baseArr, mid + 1, segmentEnd, segmentTree, (segmentIndex << 1) + 2);

    return segmentTree[segmentIndex];
}

/* returns pointer to heap like structure created */
int* constructST(int baseArr[], int n)
{
    int sizeCap = 2*(1 << (int)ceil(log2(n)))  - 1;
    int* segmentTree = new int[sizeCap];
    constructSTUtil(baseArr, 0, n-1, segmentTree, 0);

    return segmentTree;
}

/*Query in a range*/
int getSumUtil(int* segmentTree, int segmentStart, int segmentEnd, int left, int right, int segmentIndex)
{
    if (segmentStart > right || segmentEnd < left) return 0;

    if (left <= segmentStart && right >= segmentEnd) return segmentTree[segmentIndex];

    int mid = getMid(segmentStart, segmentEnd);

    return getSumUtil(segmentTree, segmentStart, mid, left, right, (segmentIndex << 1) + 1)
            + getSumUtil(segmentTree, mid+1, segmentEnd, left, right, (segmentIndex << 1) + 2);
}

int getSum(int* segmentTree, int n, int left,int right)
{
    return getSumUtil(segmentTree, 0, n-1, left, right, 0);
}


/* Update value of a single element and reflect in all parent nodes */

void updateValue(int arr[], int* segmentTree, int n, int i, int updatedValue)
{

}

int main()
{
    int n;
    scanf("%d", &n);
    int baseArr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &baseArr[i]);
    }
    int* segmentTree = constructST(baseArr, n);
    int sizeCap = 2*(1 << (int)ceil(log2(n)))  - 1;
    for (int i = 0; i < sizeCap; i++)
    {
        printf("%d ", segmentTree[i]);
    }
    
    int queries;
    scanf("%d", &queries);

    for (int i = 0; i < queries; i++)
    {
        int left, right;
        scanf("%d %d", &left, &right);
        printf("%d\n", getSum(segmentTree, n, left, right));
    }
    
    return 0;
}