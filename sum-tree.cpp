#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
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
bool isSumTree(struct Node* node);
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent; 
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
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
     std::cout << isSumTree(root) << endl;
  }
  return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// Should return true if tree is Sum Tree, else false
void isSumTreeHelper(Node* node, bool& sumTreeFlag) {
    int leftSum = 0, rightSum = 0;
    if (node != NULL && node -> left != NULL) {
      leftSum =  (node -> left) -> data;
      isSumTreeHelper(node -> left, sumTreeFlag);
    }

    if (node != NULL && node -> right != NULL) {
      rightSum = (node -> right) -> data;
      isSumTreeHelper(node -> right, sumTreeFlag);
    }

    if ( (leftSum || rightSum) &&  
        ((leftSum + rightSum) != (node -> data) )) {
        sumTreeFlag = false;
    } 
}

bool isSumTree(Node* root)
{
     // Your code here
    bool sumTreeFlag = true;
    int leftSum = 0, rightSum = 0;
    if (root != NULL && root -> left != NULL) {
      leftSum =  (root -> left) -> data;
      isSumTreeHelper(root -> left, sumTreeFlag);
    }

    if (root != NULL && root -> right != NULL) {
      rightSum =  (root -> right) -> data;
      isSumTreeHelper(root -> right, sumTreeFlag);
    }  

    if ((leftSum + rightSum) != (root ->data)) {
      sumTreeFlag = false;
    }
     return sumTreeFlag;
}