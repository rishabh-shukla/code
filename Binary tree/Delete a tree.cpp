#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
int height(node *root)
{
    if(root==NULL)
        return 0;
    else return max(height(root->left),height(root->right))+1;
}
node* newNode(int data)
{
    node* n=new node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void deleteTree(node* root)
{
    if(root==NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    cout<<root->data<<" ";
    free(root);
}
int main()
{
    struct node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

   // cout<<height(root);
    deleteTree(root);
}

