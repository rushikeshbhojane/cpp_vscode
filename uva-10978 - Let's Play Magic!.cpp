#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // your code goes here
    int noOfCards;
    while (cin >> noOfCards && noOfCards != 0)
    {
        string cards[noOfCards], orderedCards[noOfCards];
        bool orderedCardsFilled[noOfCards] = {false};
        string cardName, nameToBeSpelt;
        int counter  = 0, currentTotalCards = noOfCards;
        for (int i = 0; i < noOfCards; i++)
        {
            cin >> cardName >> nameToBeSpelt;
            int cardNameLength = nameToBeSpelt.length();
            while (cardNameLength > 0)
            {
                /* code */
                if (!orderedCardsFilled[counter]) {
                    cardNameLength--;
                    if (cardNameLength == 0) {
                        orderedCardsFilled[counter] = true;
                        orderedCards[counter] = cardName;
                        counter++;
                        if (counter == noOfCards) {
                                counter = 0;
                        }                        
                        break;
                    }
                }
                    counter++;
                    if (counter == noOfCards) {
                        counter = 0;
                    }
            }
        }   
        for (int i = 0; i < noOfCards; i++)
        {
            cout << orderedCards[i];
            if (i != noOfCards - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}
