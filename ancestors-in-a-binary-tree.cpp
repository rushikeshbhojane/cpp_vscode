#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
bool printAncestors(struct Node *root, int target);
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        std::cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int a;
     std::cin>>a;
    printAncestors(root, a);
  }
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
// Function should print all the ancestor of the target node
bool printAncestorsUtil(struct Node *root, int target) {
    if (root != NULL) {
        if (root -> data == target) {
            return true;
        }

        if (root -> left != NULL) {
            if (printAncestorsUtil(root -> left, target)) {
                cout << root ->  data <<  " ";
                return true;
            }
        }
        
        if (root -> right != NULL) {
            if (printAncestorsUtil(root -> right, target)) {
                cout << root ->  data <<  " ";
                return true;
            }
        }
    }
    return false;
}
bool printAncestors(struct Node *root, int target)
{
     // Code here
    if(printAncestorsUtil(root, target)) {
        cout << "\n";
    }
    return false;
}