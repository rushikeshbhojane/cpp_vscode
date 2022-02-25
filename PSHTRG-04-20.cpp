#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
struct node {
    int segmentEnd, segmentStart;
    vector<long long> sides;
};
ll* sequence;
node *segmentTree;

void build(int index, int segmentStart, int segmentEnd) {
    if (segmentStart == segmentEnd) {
        segmentTree[index].segmentStart = segmentTree[index].segmentEnd = segmentStart;
        segmentTree[index].sides.clear();
        segmentTree[index].sides.push_back(sequence[segmentStart]);
        return;
    } else {
        build(2 * index + 1, segmentStart, (segmentStart + segmentEnd) / 2);
        build(2 * index + 2, (segmentStart + segmentEnd) / 2 + 1, segmentEnd);
        int l1 = segmentTree[2*index + 1].sides.size();
        int l2 = segmentTree[2*index + 2].sides.size();

        vector<ll> temp;
        int p1 = 0, p2 = 0;

        while (p1 < l1 || p2 < l2)
        {
            if (p1 == l1) temp.pb(segmentTree[2*index + 2].sides[p2++]);  
            else if (p2 == l2) temp.pb(segmentTree[2*index + 1].sides[p1++]);
            else {
                ll ele1 = (segmentTree[2*index + 1].sides[p1]);
                ll ele2 = (segmentTree[2*index + 2].sides[p2]);
                ele1 <= ele2 
                ? temp.pb(segmentTree[2*index + 1].sides[p1++])
                : temp.pb(segmentTree[2*index + 2].sides[p2++]);
            }
        }

        int p = l1 + l2 -3;
        while (p > 0)
        {
            ll a = temp[p], b = temp[p+1], c = temp[p + 2];
            if ((a + b > c) && (b + c > a) && (a + c > b) ) break;
            if (p == 0) break;
            p--;
        }
        p  = (p < 0) ? 0 : p;
        while (p < l1 + l2) (segmentTree + index)->sides.pb(temp[p++]);
    }
}

void update(int index, int segmentStart, int segmentEnd,
                int indexToBeUpdated, int value) {
    if (indexToBeUpdated < segmentStart || indexToBeUpdated > segmentEnd) return;

    if (segmentStart == segmentEnd && index == segmentStart) {
        segmentTree[index].sides[0] = value;
        return;
    } else {
        update(2 * index + 1, segmentStart, (segmentStart + segmentEnd) / 2,
                        indexToBeUpdated, value);
        update(2 * index + 2, (segmentStart + segmentEnd) / 2 + 1, segmentEnd,
                        indexToBeUpdated, value);
        int l1 = segmentTree[2*index + 1].sides.size();
        int l2 = segmentTree[2*index + 2].sides.size();

        vector<ll> temp;
        int p1 = 0, p2 = 0;

        while (p1 < l1 || p2 < l2)
        {
            if (p1 == l1) temp.pb(segmentTree[2*index + 2].sides[p2++]);  
            else if (p2 == l2) temp.pb(segmentTree[2*index + 1].sides[p1++]);
            else {
                ll ele1 = segmentTree[2*index + 1].sides[p1];
                ll ele2 = segmentTree[2*index + 2].sides[p2];
                ele1 <= ele2 
                ? temp.pb(segmentTree[2*index + 1].sides[p1++])
                : temp.pb(segmentTree[2*index + 2].sides[p2++]);
            }  
        }

        int p = l1 + l2 -3;
        while (p > 0)
        {
            ll a = temp[p], b = temp[p+1], c = temp[p + 2];
            if ((a + b > c) && (b + c > a) && (a + c > b) ) break;
            if (p == 0) break;
            p--;
        }
        p  = (p < 0) ? 0 : p;
        segmentTree[index].sides.clear();
        while (p < l1 + l2) segmentTree[index].sides.pb(temp[p++]);
    }
}

vector<ll> getSides(
    int index, int segmentStart, int segmentEnd,
    int left, int right
) {
    if (left > segmentEnd || right < segmentStart) {
        vector<ll> emptyVector; return emptyVector;
    } else if (left <= segmentStart && segmentEnd <= right) return segmentTree[index].sides;
    else {
        vector<ll> lv = getSides(
                        2*index+1, segmentStart, (segmentStart + segmentEnd)/2,
                        left, right);
        
        vector<ll> rv = getSides(
                        2*index+2, (segmentStart + segmentEnd)/2 + 1, segmentEnd,
                        left, right);

        vector<ll> temp;
        int lvSize = lv.size(), rvSize = rv.size();
        int p1 = 0, p2 = 0;

        while (p1 < lvSize || p2 < rvSize)
        {
            if (p1 == lvSize) temp.pb(rv[p2++]);  
            else if (p2 == rvSize) temp.pb(lv[p1++]);
            else {
                ll ele1 = lv[p1];
                ll ele2 = rv[p2];
                ele1 <= ele2
                ? temp.pb(lv[p1++])
                : temp.pb(rv[p2++]);
            }  
        }

        int p = lvSize + rvSize -3;
        while (p > 0)
        {
            ll a = temp[p], b = temp[p+1], c = temp[p + 2];
            if ((a + b > c) && (b + c > a) && (a + c > b) ) break;
            if (p == 0) break;
            p--;
        }
        p  = (p < 0) ? 0 : p;
        vector<ll> returnVector;
        while (p < lvSize + rvSize) returnVector.pb(temp[p++]);

        return returnVector;
    }
    
}
int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

	sequence = (ll*)(malloc(N*sizeof(ll)));
	segmentTree = (node*)(malloc(4*N*sizeof(node)));
    
    for (int i = 0; i < N; i++)  cin >> sequence[i];
    build(0, 0, N-1);

    for (int i = 0; i < Q; i++)
    {
        int arg1, arg2, arg3;
        scanf("%d %d %d", &arg1, &arg2, &arg3);
        if (arg1 == 1) {
            update(0, 0, N-1, --arg2, arg3);
        } else {
            vector<ll> sides = getSides(0, 0, N-1, --arg2, --arg3);
            ll ans = 0;
            int p = sides.size() - 3;
            while (p >= 0)
            {
                ll a = sides[p], b = sides[p+1], c = sides[p + 2];
                if(a+b>c && b+c>a && c+a>b) {
					ans = a+b+c;
					break;
				}
				p--;
            }
            printf("%lld\n", ans);
        }
    }
    
    return 0;
}