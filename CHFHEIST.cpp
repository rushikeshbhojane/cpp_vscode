#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)  {
	    int D, d, P, Q, total = 0;
	    scanf("%d %d %d %d", &D, &d, &P, &Q);
	    for (int i = 0; i < D;) {
	        if (i+ d < D) {
	            total += d*(P);
	            i+= d;
	        } else {
	            total += (D - i) * P;
	            i += (D - i);
	        }
	        P += Q;
	    }
	    printf("%d\n", total);
	}
	return 0;
}