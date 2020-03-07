#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    // your code goes here
    int no_of_stacks, set_no = 0;
    while ((cin >> no_of_stacks) 
            && no_of_stacks != 0)
    {
        /* code */
        set_no++;
        string line;
        getline(cin, line);
        istringstream is(line);
        vector<int> bricks;
        int inp, sum = 0;
        for (int i = 0; i < no_of_stacks; i++)
        {
            cin >> inp;
            sum += inp;
            bricks.push_back(inp);
        }
        int bricks_per_stack = sum/ no_of_stacks;
        int moves = 0;
        for (int i: bricks)
        {
            if (i > bricks_per_stack) {
                moves += (i - bricks_per_stack);
            }
        }
        
        cout << "Set #" << set_no << "\n";
        cout << "The minimum number of moves is " << moves << "." << "\n" << "\n";

    }
    
    return 0;
}
