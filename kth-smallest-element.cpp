// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends//User function template for C++

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int randomNo(int userBeg, int userEnd) {
    int outPut = rand()%((userEnd - userBeg) + 1) + userBeg;
}

int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    int randomLySelectedEle = randomNo(l, r);
    swap(arr[randomLySelectedEle], arr[r]);
    int pivot = arr[r];
    int i =  l - 1;
    for (int j = l; j <= r-1; j++)
    {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(arr[++i], arr[r]);
    if (i == k-1) {
        return arr[i];
    } else {
        if (k-1 < i) {
            return kthSmallest(arr, l, i-1, k);
        } else {
            return kthSmallest(arr, i+1, r, k);
        }
    }
}