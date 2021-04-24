#include <iostream>
using namespace std;

int main() {
    // your code goes here
    int duration, no_of_records;
    float down_payment, amount;
    while (cin >> duration
            && cin >> down_payment
            && cin >> amount
            && cin >> no_of_records
            && duration != -99 )
    {
        int prevMonth  = 0,  currMonth;
        float currentDeprection, prevDeprecation, deprecation[duration + 10];
        for (int i = 0; i < no_of_records; i++)
        {
            cin >> currMonth >> currentDeprection;
            deprecation[currMonth] = currentDeprection;
            for (int j = prevMonth +  1; j < currMonth; j++)
            {
                deprecation[j] = prevDeprecation;
            }
            prevMonth = currMonth;
            prevDeprecation = currentDeprection;
        }
        for (int i = prevMonth + 1; i <= duration; i++)
        {
            deprecation[i] = prevDeprecation;
        }
        
        float total_amount = down_payment + amount, paymentPerMonth = amount / (1.0 * duration)
                    , amount_owed =  amount;
        for (int i = 0; i <= duration ; i++)
        {
            if (i != 0) amount_owed = amount_owed - paymentPerMonth; 
            total_amount = (1 - deprecation[i]) * total_amount;
            if (amount_owed < total_amount) {
                cout << i << " " <<  ((i == 1) ? "month": "months")   << "\n";
                break;
            }
        }
        
    }
     
    return 0;
}
