// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
        void checkCongruenncy(
            int A[], int B[], int C[],
            int* l1, int* l2, int* l3,
            int n1, int n2, int n3,
            int* intersection
        ) {
            int templ1 = *l1, templ2 = *l2, templ3 = *l3;
            if (A[*l1] == B[*l2]
                && B[*l2] == C[*l3]) {
                *intersection++;
                while (templ1 < n1 && A[templ1] ==  A[*l1]) templ1++;
                *l1 = templ1;
                
                while (templ2 < n2 && B[templ2] ==  B[*l2]) templ2++;
                *l2 = templ2;
                
                while (templ3 < n3 && A[templ1] ==  C[*l3]) templ3++;
                *l3 = templ3;
            }
        }

       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            int l1 = 0, l2 = 0, l3 = 0, intersection = 0;
            while (l1 < n1 && l2 < n2  && l3 < n3) {
                if (A[l1] < B[l2] || A[l1] < C[l3]) l1++;
                
                else if (B[l2] < A[l1] || B[l2] < C[l3] ) l2++;
                else if (C[l3] < A[l1] || C[l3] < B[l2] ) l3++; 
                checkCongruenncy(A, B, C, &l1, &l2, &l3, n1, n2, n3, &intersection);
            }
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends