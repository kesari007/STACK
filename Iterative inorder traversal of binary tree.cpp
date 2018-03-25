#include<bits/stdc++.h>
using namespace std ;
struct node{
    int data ;
    struct node * left ;
    struct node * right ;
};
struct node *Newnode(int data)
{
    struct node * node =(struct node *)malloc(sizeof(struct node ));
    node->data=data;
    node->left =node->right =NULL;
    return node ;
}
 stack<struct node *>s1;
void iterativeInorder(struct node *root)
{

    if(root->right!= NULL)                  // INORDER = LNR SO WE ARE STORING IN REVERSE ORDER I.E. RNL !!
        iterativeInorder(root->right);
    s1.push(root);
    if(root->left!= NULL)
        iterativeInorder(root->left);
}
void printstack()
{
    while(!s1.empty()){
            struct node *k=s1.top();
        cout << k->data << " " ;
        s1.pop();
    }
}
int main()
{
    cout << "creating binary tree \n" ;
    struct node * root= Newnode(10);
    root->left=Newnode(0);
    root->right=Newnode(-10);
    root->left->left=Newnode(5);
    root->left->right=Newnode(6);
    root->right->left=Newnode(5);
    root->right->right=Newnode(11);
      iterativeInorder(root);
      printstack();
      
      return 0;
}
