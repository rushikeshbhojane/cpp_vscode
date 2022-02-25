#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> split_string(string);
int merge(vector<int>& arr, int left, int mid, int right) {
    int i = left, j = mid+1, swaps = 0;
    vector<int> arr_temp;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            arr_temp.push_back(arr[i++]);
        } else {
            swaps++;
            arr_temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) arr_temp.push_back(arr[i++]);
    while (j <= right) arr_temp.push_back(arr[j++]); 
    for (int k = left; k <= right; k++) arr[k] = arr_temp[k-left];
    return swaps;
}
// Complete the minimumSwaps function below.
int mergeSort(vector<int>& arr, int left, int right) {
    int swaps = 0;
    if (left < right) {
        int mid = left + (right-left)/2;
        swaps += mergeSort(arr, left, mid);
        swaps += mergeSort(arr, mid+1, right);
        swaps += merge(arr, left, mid, right);
    }
    return swaps;
}

int minimumSwaps(vector<int> arr) {
    int n = arr.size();
    int inversions = mergeSort(arr, 0, n-1);
    return inversions;
}

int main()
{

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    cout << res << endl;
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
