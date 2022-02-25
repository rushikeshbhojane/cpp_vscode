/*
  Beautiful Codes are MUCH better than 'Shorter' ones !
user  : triveni
date  : 22/02/2018
time  : 02:58:00
*/
#include <bits/stdc++.h>

using namespace std;

#define pii std::pair<int, int>
#define vi std::vector<int>
#define sz(v) (int)(v.size())
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define each(it, s) for (auto it = s.begin(); it != s.end(); ++it)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define scan(n) scanf("%d", &n)
#define scan2(n, m) scanf("%d%d", &n, &m)
#define pin(n) printf("%d\n", n)
#define pis(n) printf("%d ", n)
#define pll(n) printf("%lld\n", n)
#define X first
#define Y second

typedef long long ll;
ll mod = 1000000007;

inline int pow_(ll a, int n, int p = mod)
{
    int r = 1;
    while (n)
    {
        if (n & 1)
            r = r * a % p;
        n >>= 1;
        a = a * a % p;
    }
    return r;
}
inline int inv_(int a) { return pow_(a, mod - 2, mod); }
inline int add(int a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}
inline void adds(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
inline int mul(int a, int b) { return a * 1ll * b % mod; }
inline void muls(int &a, int b) { a = a * 1ll * b % mod; }
inline int sub(int a, int b)
{
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

const int M = 50;

int tree[1 << 18][M];
int inp[100100];
int tmp[M];

void merge(int *a, int *b, int *c)
{
    int j = 0, k = 0;
    for (int i = 0; i < M && a[i] && k < M; ++i)
    {
        while (k < M && j < M && b[j] >= a[i])
            c[k++] = b[j++];
        if (k < M)
            c[k++] = a[i];
    }
    while (k < M && j < M && b[j])
        c[k++] = b[j++];
}

int qq[M];

void merge(int *a)
{
    int j = 0, k = 0;
    for (int i = 0; i < M && a[i] && k < M; ++i)
    {
        while (k < M && j < M && qq[j] >= a[i])
            tmp[k++] = qq[j++];
        if (k < M)
            tmp[k++] = a[i];
    }
    while (k < M && j < M && qq[j])
        tmp[k++] = qq[j++];
    memcpy(qq, tmp, k * sizeof(int));
}

void build(int rt, int l, int r)
{
    if (l == r)
    {
        tree[rt][0] = inp[l];
        return;
    }
    int m = (l + r) >> 1, left = rt << 1, right = left | 1;
    build(left, l, m);
    build(right, m + 1, r);
    merge(tree[left], tree[right], tree[rt]);
}

void update(int rt, int l, int r, int idx, int val)
{
    if (l == r)
    {
        tree[rt][0] = val;
        return;
    }
    int m = (l + r) >> 1, left = rt << 1, right = left | 1;
    if (idx <= m)
        update(left, l, m, idx, val);
    else
        update(right, m + 1, r, idx, val);
    merge(tree[left], tree[right], tree[rt]);
}

void query(int rt, int l, int r, int i, int j)
{
    if (i <= l && r <= j)
    {
        merge(tree[rt]);
        return;
    }
    int m = (l + r) >> 1, left = rt << 1, right = left | 1;
    if (i <= m)
        query(left, l, m, i, j);
    if (m + 1 <= j)
        query(right, m + 1, r, i, j);
}

int main()
{
    int n, q;
    scan2(n, q);
    rep(i, n) scan(inp[i + 1]);
    build(1, 1, n);
    while (q--)
    {
        int type, l, r;
        scan(type);
        scan2(l, r);
        if (type == 1)
        {
            update(1, 1, n, l, r);
        }
        else
        {
            memset(qq, 0, sizeof(qq));
            query(1, 1, n, l, r);
            ll ans = 0;
            for (int i = 0; i + 2 < M && qq[i + 2]; ++i)
            {
                if (qq[i] < qq[i + 1] + qq[i + 2])
                {
                    ans = qq[i];
                    ans += qq[i + 1] + qq[i + 2];
                    break;
                }
            }
            pll(ans);
        }
    }
    return 0;
}
