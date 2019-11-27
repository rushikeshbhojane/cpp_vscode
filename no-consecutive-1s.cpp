#include <vector>
#include <algorithm>
using namespace std;
void countConsecutiveOnes(int nextChar, int n,  int& count) {
    if (n > 0) {
        countConsecutiveOnes(0, n-1, count);
        if (nextChar == 0) {
            countConsecutiveOnes(1, n-1, count);
        }
    } else {
        count++;
    }
}
int countConsecutiveOnesAux(int n) {
    int count = 0;
    countConsecutiveOnes(0, n-1, count);
    countConsecutiveOnes(1, n-1, count);
    return count;
}
int main() {
    // your code goes here
    int t;
    cin >> t;
    while(t--)  {
        int n;
        cin >> n;
        cout << countConsecutiveOnesAux(n) << "\n";
    }
    return 0;
}
