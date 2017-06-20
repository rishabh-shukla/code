#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
int main()
{
    node* root=new node;
    root->data=1;
    root->left=new node;
    root->left->data=2;
    root->right=new node;
    root->right->data=3;
    cout<<root->data<<root->left->data<<root->right->data;
}
