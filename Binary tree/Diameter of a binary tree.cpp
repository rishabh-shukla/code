#include<iostream>
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
int diameter(node* root)
{
    if(root==NULL)
        return 0;
    int l=height(root->left);
    int r=height(root->right);
    int dl=diameter(root->left);
    int dr=diameter(root->right);
    return max(l+r+1,max(dl,dr));
}
int main()
{
    struct node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<diameter(root);
}

