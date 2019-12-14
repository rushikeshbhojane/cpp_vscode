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
int getLevel(struct Node *node, int target);
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
        std::cout<<a<<endl;
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
    std::cout<<getLevel(root, a)<<endl;
  }
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*
Structure of the node of the binary tree is
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return level of the target node
bool getLevelUtil(struct Node *root, int target, int& level) {
    if (root != NULL) {
        if (root -> data == target) {
            level++;
            return true;
        }

        if (root -> left != NULL) {
            if (getLevelUtil(root->left,target,level)) {
                level++;
                return true;
            }
        }
        
        if (root -> right != NULL) {
            if (getLevelUtil(root->right,target,level)) {
                level++;
                return true;
            }            
        }
    }

    return false;
}
int getLevel(struct Node *node, int target)
{
     // Code here
    int level = 0;
    getLevelUtil(node,target,level);
    return level;
}
