#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long special = 0;
    for (int i = 0; i < n; i++ ) {
        special++;
        int j = i+1;
        while(j < n) {
            if (s[j] == s[i]) {
                j++;
                special++;
            } else {
                break;
            }
        }
        
        
        if ( i + 2*(j-i) < n) {
            bool isSpecial  = true;
            for (int k = j+1; k < i + 2*(j-i) + 1; k++) {
                if (s[k] != s[i]) {
                    isSpecial = false;
                    break;
                }
            }
            if (isSpecial) special++;
        }
    }
    return special;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
