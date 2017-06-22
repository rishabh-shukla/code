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
int isSumProperty(struct node* node)
{
  int left_data = 0,  right_data = 0;
 if(node == NULL ||
     (node->left == NULL && node->right == NULL))
    return 1;
  else
  {
    if(node->left != NULL)
      left_data = node->left->data;
    if(node->right != NULL)
      right_data = node->right->data;
    if((node->data == left_data + right_data)&&
        isSumProperty(node->left) &&
        isSumProperty(node->right))
      return 1;
    else
      return 0;
  }
}
int main()
{
    struct node *root  = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);
    cout<<isSumProperty(root);
}


