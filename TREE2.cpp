#include<iostream>
#include<map>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N, diffCount = 0;
        scanf("%d", &N);
        map<int, int> countArr;
        for (int i = 0; i < N; i++)
        {
            int temp;
            scanf("%d", &temp);
            if (temp != 0) {
                if (countArr.find(temp) == countArr.end()) {
                    countArr[temp] = 1;
                    temp = true;
                    diffCount++;
                } else {
                    countArr[temp]++;
                }
            }
        }
        printf("%d\n", diffCount);
    }
    
    return 0;
}