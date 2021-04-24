#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // your code goes here
    int N;
    while (cin >> N && N != 0)
    {
        int arr[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }
        int peaks = 0;
        for (int i = 0; i < N; i++)
        {
            if (i == 0) {
                if (((arr[i] > arr[N-1]) && (arr[i] > arr[i+1]))
                    || ((arr[i] < arr[N-1]) && (arr[i] < arr[i+1]))) {
                    peaks++;
                } 
            } else if (i == N - 1) {
                if (((arr[i] > arr[i-1]) && (arr[i] > arr[0]))
                    || ((arr[i] < arr[i-1]) && (arr[i] < arr[0]))) {
                    peaks++;
                }
            } else {
                if (((arr[i] > arr[i-1]) && (arr[i] > arr[i+1]))
                    || ((arr[i] < arr[i-1]) && (arr[i] < arr[i+1]))) {
                    peaks++;
                }
            }
        }
        cout << peaks << "\n";

    }
    
    return 0;
}
