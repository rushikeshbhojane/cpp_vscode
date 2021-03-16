#include<iostream>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<int, int> m;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", m[i]++);
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", m[i]);
    }
    return 0;
}