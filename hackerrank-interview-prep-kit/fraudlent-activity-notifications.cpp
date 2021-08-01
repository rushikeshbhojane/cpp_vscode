#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

int activityNotifications(vector<int> expenditure, int d) {
        int n = expenditure.size(), notifications = 0;
        int maxElement =  *max_element(expenditure.begin(), expenditure.end());
        vector<int> frequency(maxElement+1, 0);
        
        for (int i = 0; i < d; i++) {
            frequency[expenditure[i]]++;
        }
        
        for (int i = d; i < n; i++) {
            int currentCount = 0;
            float median = 0;
            for(int i = 0; i <= maxElement; i++) {
                currentCount += frequency[i];
                if (d % 2) {
                    if (currentCount >= d/2) {
                        median += i * 1.0;
                        break;
                    }
                } else {
                    if (currentCount >= d/2 + 1) {
                        if (median == 0) {
                            median += i * 1.0;                        
                        }
                        median += i * 1.0;
                        break;
                    } else if (currentCount >= d/2) {
                        median += i * 1.0;
                    }
                }
            }
            if (d % 2 == 0) {
                median /= 2.0;
            }
            
            if ((1.0 * expenditure[i]) >= (2.0 * median)) notifications++;
            frequency[expenditure[i-d]]--;
            frequency[expenditure[i]]++;
        }
        
        return notifications;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

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
