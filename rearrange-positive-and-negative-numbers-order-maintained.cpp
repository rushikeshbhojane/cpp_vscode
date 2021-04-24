
// C++ program to Rearrange positive and negative
// numbers in a array
#include <iostream>
using namespace std;
 
// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Function to Rearrange positive and negative
// numbers in a array
void RearrangePosNegInsertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        if (arr[i] < 0) {
            int temp = arr[i], j = i-1;
            while(arr[j] > 0 && j >=0) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] =  temp;
        }
    }
}

// this method uses merge sort
void merge(int arr[], int left, int mid, int right) {
    int temp[right - left + 1];
    int p1 = left, p2 = mid+1, tp =0;

    while (arr[p1] < 0 && p1 <= mid) temp[tp++] = arr[p1++];

    while (arr[p2] < 0 && p2 <= right) temp[tp++] = arr[p2++];
        
    while (p1 <= mid) temp[tp++] = arr[p1++];

    while (p2 <= right) temp[tp++] = arr[p2++];

    for (int i = left, j = 0; i <= right; i++)
    {
        arr[i] = temp[j++];
    }
    
    
}

void RearrangePosNegMergeSort(int arr[], int l, int r, int n)
{
    if (l >= r) {
        return;
    }
    int mid = (l + r)/2;
    RearrangePosNegMergeSort(arr, l, mid, n);
    RearrangePosNegMergeSort(arr, mid+1, r, n);
    merge(arr, l, mid, r);
    cout << "left: " << l << " mid: " << mid << " right: " << r << endl;
    printArray(arr, n);
}


/* Driver program to test above functions */
int main()
{
    int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    RearrangePosNegMergeSort(arr, 0, n-1, n);
    printArray(arr, n);
 
    return 0;
}
