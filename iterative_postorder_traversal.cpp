// ITERATIVE POSTORDER TRAVERSAL USING 2 STACKS !
#include<bits/stdc++.h>
using namespace std ;

// A tree node
struct node{
    int data ;
    struct node* left ;
    struct node* right;

};

// A utility function to create a new tree node
struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// An iterative function to do post order traversal of a given binary tree
void postOrderIterative(struct node *root)
{
    // Creating two stacks
     stack<struct node *> s1;
     stack<struct node *> s2;

     if (root == NULL)
        return ;
    // pushing item to the first stack
     s1.push(root);
     while (!s1.empty())
     {
         // storing the top element into k
    struct node* k=s1.top();
        // Pop an item from s1 and push it to s2
         s1.pop();
         s2.push(k);
        // Push left and right children of removed item to s1
         if(k->left != NULL)
            s1.push(k->left);
         if(k->right != NULL)
            s1.push(k->right);

     }
     // Print all elements of second stack
     while (!s2.empty())
     {
         struct node* x = s2.top() ;
         cout << x->data <<  " " ;
         s2.pop();
     }
}

// Driver program to test above functions
int main()
{
    // Let us construct the tree shown in above figure
     struct node* root = NULL;
     root = NewNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->left = newNode(6);
     root->right->right = newNode(7);

     postOrderIterative(root);

    return 0;
}
