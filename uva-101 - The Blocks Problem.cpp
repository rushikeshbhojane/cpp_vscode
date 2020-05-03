#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isInValidOperation(int block1, int block2, int currentStack[] ) {
    return currentStack[block1] == currentStack[block2]; 
}
/*this function will move block from block to move and top of it to destination block */
void moveBlocks(int blockToMove, int destinationBlock,
                int currentStack[],  vector<vector<int> >& stackDescripttion) {
    int stackOfBlock = currentStack[blockToMove];
    int stackOfDestinationBlock = currentStack[destinationBlock];
    vector<int>::iterator index = find(stackDescripttion[stackOfBlock].begin(), stackDescripttion[stackOfBlock].end(), blockToMove);
    for (vector<int>::iterator i = index; i != stackDescripttion[stackOfBlock].end(); i++)
    {
        currentStack[*i] = stackOfDestinationBlock;
        stackDescripttion[stackOfDestinationBlock].push_back(*i);
    }
    stackDescripttion[stackOfBlock].erase(index, stackDescripttion[stackOfBlock].end());
}

void emptyTop(int block, int currentStack[],  vector<vector<int> >& stackDescripttion) {
    int stackOfBlock = currentStack[block];
    vector<int>::iterator index = find(stackDescripttion[stackOfBlock].begin(), stackDescripttion[stackOfBlock].end(), block);
    for (vector<int>::iterator i = index+1; i != stackDescripttion[stackOfBlock].end(); i++)
    {
        currentStack[*i] = *i;
        stackDescripttion[*i].push_back(*i);
    }
    stackDescripttion[stackOfBlock].erase(index+1, stackDescripttion[stackOfBlock].end());
    
}


int main () {
    int n;
    cin >> n;
    int currentStack[n];
    
    vector<vector<int> > stackDescripttion(n, vector<int>());


    for (int i = 0; i < n; i++)
    {
        currentStack[i] = i;
        stackDescripttion[i].push_back(i);
    }
    
    cin .clear();
    string actionVerb;
    while(cin >> actionVerb && actionVerb != "quit")
    {
        cin.clear();
        string actionPrep;
        int block1, block2;
        
        cin >> block1 >> actionPrep >> block2;

        if (isInValidOperation(block1, block2, currentStack)) {
            continue;
        }        
        int stackOfBlock1 = currentStack[block1];
        int stackOfBlock2 = currentStack[block1];
        if (actionVerb == "move") {
            emptyTop(block1, currentStack, stackDescripttion);
            if (actionPrep == "onto") {
                emptyTop(block2, currentStack, stackDescripttion);
            }
            moveBlocks(block1, block2, currentStack, stackDescripttion);
        } else {
            if (actionPrep == "onto") {
                emptyTop(block2, currentStack, stackDescripttion);
            }
            moveBlocks(block1, block2, currentStack, stackDescripttion);
        }

    }

    for (int i = 0; i < n; i++)
    {
        printf("%d:", i);
        if (!stackDescripttion[i].empty()) {
            printf(" ");
        }
        for (int& j: stackDescripttion[i])
        {
            printf("%d", j);
            if (&j != &stackDescripttion[i].back()) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    
    return 0;
}