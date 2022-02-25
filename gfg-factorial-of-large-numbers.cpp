#include <iostream>
using namespace std;
string Add(string number1, string number2) {
    int l1 = number1.length(), l2 = number2.length();
    if (l1  > l2) number2 = string( l1 - l2, '0').append( number2);
    else  number1 = string( l2 - l1, '0').append( number1);
    string finalSum = "";
    int lMax = max(l2, l1), carry = 0;
    for (int i = lMax-1; i >= 0; i--)
    {
        int interMediateSum =  number1[i] + number2[i] - 2 * '0' + carry;
        if (interMediateSum > 10) {
            carry =  interMediateSum/10;
            interMediateSum = interMediateSum % 10;
            char interMediateSumString = '0' + interMediateSum;
            finalSum = interMediateSumString + finalSum;
        } else {
            carry = 0;
            char interMediateSumString = '0' + interMediateSum;
            finalSum = interMediateSumString + finalSum;
        }
    }

    if (carry > 0) {
        char carryString = '0' + carry;
        finalSum = carryString + finalSum;
    } 
    return finalSum;
    
}
string multiply(string multiplicand, int multiplier) {
    string finalMultiplicand;
    int iterationCount = 0;
    while (multiplier > 0) {
        int carry = 0;
        int singleMultiplier = multiplier % 10;
        string multiplicandTemp = "";
        if (iterationCount != 0) multiplicandTemp += "0"; 

        for (int i = multiplicand.size() - 1; i >= 0; i--) {
            if (singleMultiplier == 0) {
                break;
            }

            int singleProduct
                = ((multiplicand[i] - '0') * singleMultiplier + carry);
            if (singleProduct > 10) {
                carry = singleProduct / 10;
                singleProduct = singleProduct % 10;
            } else {
                carry = 0;
            }
            char singleProductString = '0' + singleProduct;
            multiplicandTemp = singleProductString + multiplicandTemp;
        }
        char carryString = '0' + carry;
        if (carry != 0) multiplicandTemp = carryString + multiplicandTemp;
        multiplier = multiplier / 10;

        if (iterationCount == 0) finalMultiplicand = multiplicandTemp;
        else finalMultiplicand = Add(finalMultiplicand, multiplicandTemp);
        iterationCount++;
    }
    return finalMultiplicand;
}
string factorial(int N) {
    string product = "1";
    for (int i = 1; i <= N; i++) {
        product = multiply(product, i);
    }
    return product;
}
int main() {
	//code
	int t;
	scanf("%d", &t);
	while (t--) {
	    int N;
	    scanf ("%d", &N);
	    cout << factorial(N) << "\n";
	}
	return 0;
}