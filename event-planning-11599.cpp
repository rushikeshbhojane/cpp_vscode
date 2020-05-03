#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // your code goes here
    long long  participants, budget, hotels, weeks;
    while(cin >> participants 
            && cin >> budget
            && cin >> hotels
            && cin >> weeks)  {
        long long  price, total_price = 6*1e9;
        for (long long  i = 0; i < hotels; i++)
        {
            cin >> price;
            for (long long  j = 0; j < weeks; j++)
            {
                long long  availabilty;
                cin >> availabilty;
                if (availabilty >= participants) 
                    total_price = min(price * participants, total_price);
            }
        }
        if (total_price > budget) {
            cout << "stay home" << "\n";
        } else {
            cout << total_price << "\n";
        }
        
    }
    return 0;
}
