#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left,*right;
    bool r;
};
node* leftmost(node* n)
{
    if(n==NULL)
        return NULL;
    while(n->left!=NULL)
        n=n->left;
    return n;
}
void inorder(node* root)
{
    node* cur=leftmost(root);
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        if(cur->r)
            cur=cur->right;
        else cur=leftmost(cur->right);
    }
}
int main()
{
    node* root=new node;
    root->data=1;
    root->left=new node;
    root->left->data=2;
    root->left->left=NULL;
    root->left->right=NULL;
    root->right=new node;
    root->right->data=3;
    root->right->left=NULL;
    root->right->right=NULL;
    inorder(root);
}
