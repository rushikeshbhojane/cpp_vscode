#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> freqQuery(vector<vector<int>> queries) {
    // ofstream fout(getenv("OUTPUT_PATH"));
    map<int, int> elementCount;
    map<int, int> frequencyCount;
    vector<int> soln;
    for (vector<int> q: queries) {
        switch(q[0]) {
            case 1:
                if (frequencyCount[elementCount[q[1]]] > 0) {
                    frequencyCount[elementCount[q[1]]]--;
                }
                elementCount[q[1]]++;
                frequencyCount[elementCount[q[1]]]++;
            break;
            
            case 2:
                if (elementCount[q[1]] > 0) {
                    frequencyCount[elementCount[q[1]]]--;
                    elementCount[q[1]]--;
                    if(elementCount[q[1]] > 0) {
                        frequencyCount[elementCount[q[1]]]++;
                    }
                }
            break;
            
            default:
                if (frequencyCount[elementCount[q[1]]] > 0) cout << "1\n";
                else  cout << "0\n"; 
            break;
        }
    }
    // fout.close();
    return soln;
}
int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";

        if (i != ans.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    // fout.close();

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