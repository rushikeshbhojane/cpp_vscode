#include <iostream>
#include <cstring>
using namespace std;
#define REP(i,a,b) for(int i=int(a);i <= int(b);i++)
struct soilder {
    int number;
    struct soilder* next;
    struct soilder* previous;

    soilder (int _no) {
        number = _no;
        next = NULL;
        previous = NULL;
    }
};
int main() {
    int S, B;
    while (cin >> S && cin >> B
                &&  S != 0 && B != 0)
    {


        /* code */
        struct soilder* soilderAccess[S+2];
        struct soilder* local_prev = NULL;
        struct soilder*  local_next = NULL;
        REP(i,0,S+1) {
            struct soilder* s = new soilder(i);
            soilderAccess[i] = s;
            if (local_prev != NULL) {
                local_prev -> next = s;
                s -> previous = local_prev;
            }
            local_prev = s;
        }


        cin.clear();
        REP(i,0,B-1)
        {
            /* code */
            int L, R;
            scanf("%d %d", &L, &R);
            soilderAccess[L] -> previous -> next = soilderAccess[R] -> next;
            soilderAccess[R] -> next -> previous  = soilderAccess[L] -> previous;
            int left,right;
            left = soilderAccess[L] -> previous -> number;
            right = soilderAccess[R] -> next -> number;
            cout << (left == 0 ?  "*" : to_string(left)) << " " << (right == S+1  ?  "*" : to_string(right)) << "\n";
        }
        printf("-\n");
        
    }
    
    return 0;
}