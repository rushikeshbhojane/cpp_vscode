#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int fib[103] = {0, 1, 2, 0}, last  = 2;
int countConsecutiveOnesAux(int n) {
    if (n > last) {
        for (int i = last + 1; i <= n; i++) {
            fib[i] = (fib[i-1] + fib[i-2]) %  1000000007;
        }
        last = n;
    }
    return fib[n];
}
int main() {
    // your code goes here
    int t;
    cin >> t;
    while(t--)  {
        int n;
        cin >> n;
        cout << countConsecutiveOnesAux(n + 1) << "\n";
    }
    return 0;
}
