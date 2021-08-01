#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int makeAnagram(string a, string b) {
    int deletions = 0;
    vector<int> count_a(26, 0);
    vector<int> count_b(26, 0);
    
    for (char c: a) count_a[c - 'a']++;
    for (char c: b) count_b[c - 'a']++;
    
    for (int i = 0; i < 26; i++) {
        deletions += abs(count_b[i] - count_a[i]);
    }
    
    return deletions;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
