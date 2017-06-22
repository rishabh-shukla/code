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
bool isbalanced(node* root)
{
    int l,r;
    if(root==NULL)
        return 1;
    l=height(root->left);
    r=height(root->right);
    if(abs(l-r)<=1 && isbalanced(root->left) && isbalanced(root->right))
        return 1;
    return 0;
}
int main()
{
    struct node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<isbalanced(root);

}

