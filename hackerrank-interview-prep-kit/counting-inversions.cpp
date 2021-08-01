#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
void merge (vector<int>& arr, int l, int m,  int r, long& inversions) {
    int i = l;
    int j =  m+1;
    vector<int> temp;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
           temp.push_back(arr[i++]);
        } else {
            inversions += (l - i + 1);
            temp.push_back(arr[j++]);
        }
    }
    
    while(i <= m) {
        temp.push_back(arr[i++]);        
    }
    
    while(j <= r) {
        temp.push_back(arr[j++]);        
    }
    
    int count = 0;
    for (int k = l; k <= r; k++) {
        arr[k] = temp[count++];
    }
}
void mergeSort(vector<int>& arr, int l, int r, long& inversions) {
    if (l >= r) {
        return;
    }
    int mid = l + (r-l)/2;
    mergeSort(arr, l, mid, inversions);
    mergeSort(arr, mid+1, r, inversions);
    merge(arr, l, mid, r, inversions);
}

long countInversions(vector<int> arr) {
    long inversions = 0;
    int n =  arr.size() - 1;
    mergeSort(arr, 0, n, inversions);
    return inversions;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
