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
void inc(node* node,int diff)
{
    if(node->left != NULL)
  {
    node->left->data = node->left->data + diff;
    inc(node->left, diff);
  }
  else if (node->right != NULL)
  {
    node->right->data = node->right->data + diff;
    inc(node->right, diff);
  }
}
void convert(node *node)
{
    int l=0,r=0,diff;
    if(node==NULL ||
       (node->left==NULL && node->right==NULL))
        return ;
    else
    {
        convert(node->left);
        convert(node->right);
        if(node->left==NULL)
            l=node->left->data;
        if(node->right==NULL)
            r=node->right->data;
        diff=l+r-node->data;
        if(diff>0)
            node->data+=diff;
        if(diff<0)
            inc(node,-diff);
    }
}
void printInorder(struct node* node)
{
  if (node == NULL)
    return;
  printInorder(node->left);
  cout<<node->data<<" ";
  printInorder(node->right);
}
int main()
{
    struct node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);

    printInorder(root);
    convert(root);
    cout<<'\n';
    printInorder(root);
}

