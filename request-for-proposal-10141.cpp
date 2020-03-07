#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
using namespace std;

int main() {
    // your code goes here
    int no_of_requirements, no_of_proposals, countRFP  = 0;
    while(cin >> no_of_requirements 
            && cin >> no_of_proposals
            && no_of_requirements != 0
            && no_of_proposals != 0)  {
            string requirement, proposal_name;
            float price;
            int no_of_requirements_met, proposal_index;
            getline(cin , requirement);
            REP(i , 0 , no_of_requirements) {
                getline(cin , requirement);
            }
            REP(i, 0, no_of_proposals) {
                string current_proposal_name, req;
                float current_price;
                int current_no_of_requirements_met;
                getline(cin, current_proposal_name);
                cin >>  
                        current_price >> current_no_of_requirements_met;
                getline(cin, req);
                REP (j, 0, current_no_of_requirements_met) getline(cin , req); 
                if (i == 0) {
                    proposal_name = current_proposal_name;
                    price = current_price;
                    proposal_index = 1;
                    no_of_requirements_met = current_no_of_requirements_met;
                } else {
                    if (current_no_of_requirements_met > no_of_requirements_met) {
                        proposal_name = current_proposal_name;
                        price = current_price;
                        proposal_index = i + 1;
                        no_of_requirements_met = current_no_of_requirements_met;
                    } else if ((current_no_of_requirements_met 
                                    == no_of_requirements_met)
                                && (current_price < price)) {
                        proposal_name = current_proposal_name;
                        price = current_price;
                        proposal_index = i + 1;
                        no_of_requirements_met = current_no_of_requirements_met;
                    } 
                }
            }
            if (countRFP != 0) cout << "\n"; 
            cout << "RFP #" << ++countRFP << "\n";
            cout << proposal_name << "\n";
    }    
    return 0;
}
