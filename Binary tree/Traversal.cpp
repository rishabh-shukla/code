#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
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
    cout<<'\n';
    preorder(root);
    cout<<'\n';
    postorder(root);
    cout<<'\n';
}

