#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
  struct node *nextRight;
};
void connectRecur(struct node* p);
void connect (struct node *p)
{
    p->nextRight = NULL;
    connectRecur(p);
}
void connectRecur(struct node* p)
{
  if (!p)
    return;
  if (p->left)
    p->left->nextRight = p->right;
  if (p->right)
    p->right->nextRight = (p->nextRight)? p->nextRight->left: NULL;
  connectRecur(p->left);
  connectRecur(p->right);
}
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->nextRight = NULL;

  return(node);
}
int main()
{
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  connect(root);
  printf("Following are populated nextRight pointers in the tree "
          "(-1 is printed if there is no nextRight) \n");
  printf("nextRight of %d is %d \n", root->data,
         root->nextRight? root->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->data,
        root->left->nextRight? root->left->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->right->data,
        root->right->nextRight? root->right->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->left->data,
        root->left->left->nextRight? root->left->left->nextRight->data: -1);
}
