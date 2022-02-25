#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#define ll long long
#define pb push_back
#define x first
#define y second    
#define mp make_pair
#define sz(a) ((int)(a.size()))

using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;

int add(int a, int b)
{
    return a + b >= mod ? a + b - mod : a + b;
}

int sub(int a, int b)
{
    return a - b < 0 ? a - b + mod : a - b;
}

int mult(int a, int b)
{
    return a * (ll)b % mod;
}

int modExp2(int exp)
{
    int soln = 1, multiplicand = 2;
    while (exp)
    {
        if (exp & 1) soln = mult(soln, multiplicand);
        multiplicand = mult(multiplicand, multiplicand);
        exp = exp >> 1;
    }
    return soln;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int N;
        scanf("%d", &N);
        int arr[N];
        int solnArr[N];

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }
        
        for (int i = 1; i <= N; i++)
        {
            solnArr[N-i] = modExp2(i - 1);
        }

        for (int i = 0; i < N; i++)
        {
            printf("%d", solnArr[i]);
            if (i != N-1) printf(" ");
        }
        
        printf("\n");

    }
    
    return 0;
}