#include<stdio.h>
#include<stdlib.h>
#define bool int
#define true 1
#define false 0
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
bool IsFoldableUtil(struct node *n1, struct node *n2);
bool IsFoldable(struct node *root)
{
     if (root == NULL)
     {  return true;  }

     return IsFoldableUtil(root->left, root->right);
}
bool IsFoldableUtil(struct node *n1, struct node *n2)
{
    if (n1 == NULL && n2 == NULL)
    {  return true;  }
    if (n1 == NULL || n2 == NULL)
    {  return false; }
    return IsFoldableUtil(n1->left, n2->right) &&
           IsFoldableUtil(n1->right, n2->left);
}
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
int main(void)
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->right  = newNode(4);
  root->right->left = newNode(5);
  if(IsFoldable(root) == true)
  { printf("\n tree is foldable"); }
  else
  { printf("\n tree is not foldable"); }
}
