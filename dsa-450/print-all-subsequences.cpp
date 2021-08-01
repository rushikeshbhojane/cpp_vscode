#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

void formSubsequence(string s, int n, int current, set<string>& subs, string formed) {
    if (current == n) {
        if (!formed.empty())
        {
            subs.insert(formed);
        }
        
    } else {
        formSubsequence(s, n, current+1, subs, formed);
        formSubsequence(s, n, current+1, subs, formed+s[current]);
    }
}
int main() {
	string s;
	cin >> s;
	set<string> subs;
	formSubsequence(s, s.length(), 0, subs, "");
	
	for(string soln : subs) {
	    cout << soln << endl;
	}
	return 0;
}