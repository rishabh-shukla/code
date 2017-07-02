#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node* newNode(int data)
{
    node* t=new node;
    t->data=data;
    t->left=t->right=NULL;
    return t;
}
node* search(node* root,int key)
{
    if(root==NULL || root->data==key)
        return root;
    else if(root->data > key)
        return search(root->left,key);
    else
        return search(root->right,key);
}
void inorder(node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
node* insert(node* root,int key)
{
    if(root==NULL)
        return newNode(key);
    if (key < root->data)
        root->left  = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}
node* minval(node* root)
{
    while(root->left)
        root=root->left;
    return root;
}
node* delnode(node* root,int key)
{
    if(root==NULL)
        return root;
    if(root->data > key)
        root->left=delnode(root->left,key);
    else if(root->data < key)
        root->right=delnode(root->right,key);
    else
    {
        if(root->left==NULL)
        {
            node* t=root->right;
            free(root);
            return t;
        }
        else if(root->right==NULL)
        {
            node* t=root->left;
            free(root);
            return t;
        }

        node* t=minval(root->right);
        root->data=t->data;
        root->right=delnode(root->right,t->data);
    }
    return root;
}
int main()
{
    node* root=NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);

    delnode(root,40);
    cout<<'\n';
    inorder(root);
    return 0;
}
