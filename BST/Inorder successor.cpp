#include<iostream>
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
node* minvalue(node* root)
{
    while(root->left)
        root=root->left;
    return root;
}
node * inOrderSuccessor(struct node *root, struct node *n)
{
    if( n->right != NULL )
        return minvalue(n->right);
    struct node *succ = NULL;
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
           break;
    }
    return succ;
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
    cout<<'\n'<<inOrderSuccessor(root,root->left)->data;
    return 0;
}
