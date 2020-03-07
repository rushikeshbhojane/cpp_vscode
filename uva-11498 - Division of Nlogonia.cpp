#include <iostream>
using namespace std;

int main() {
    // your code goes here
        int K, originX, originY, input;
        while(cin >> K && K != 0) 
        {
            scanf("%d %d", &originX, &originY);
            for (int i = 0; i < K; i++)
            {
                int pointX, pointY;
                cin >> pointX >> pointY;
                if ( originX == pointX ||  originY == pointY) {
                    printf("divisa\n");
                } else if (pointX < originX &&  pointY > originY) {
                    printf("NO\n");
                } else if (pointX > originX &&  pointY > originY) {
                    printf("NE\n");
                } else if (pointX > originX &&  pointY < originY) {
                    printf("SE\n");
                } else {
                    printf("SO\n");
                }
            };
        }
    return 0;
}
