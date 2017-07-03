#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
typedef struct node_t node_t;
struct node_t
{
    int data;
    int lCount;

    node_t* left;
    node_t* right;
};
node_t *insert_node(node_t *root, node_t* node)
{
    node_t *pTraverse = root;
    node_t *currentParent = root;
    while(pTraverse)
    {
        currentParent = pTraverse;

        if( node->data < pTraverse->data )
        {
            pTraverse->lCount++;
            pTraverse = pTraverse->left;
        }
        else
        {
            pTraverse = pTraverse->right;
        }
    }
    if( !root )
    {
        root = node;
    }
    else if( node->data < currentParent->data )
    {
        currentParent->left = node;
    }
    else
    {
        currentParent->right = node;
    }
    return root;
}
node_t* binary_search_tree(node_t *root, int keys[], int const size)
{
    int iterator;
    node_t *new_node = NULL;

    for(iterator = 0; iterator < size; iterator++)
    {
        new_node = (node_t *)malloc( sizeof(node_t) );
        new_node->data   = keys[iterator];
        new_node->lCount = 0;
        new_node->left   = NULL;
        new_node->right  = NULL;
        root = insert_node(root, new_node);
    }

    return root;
}
int k_smallest_element(node_t *root, int k)
{
    int ret = -1;
    if( root )
    {
        node_t *pTraverse = root;
        while(pTraverse)
        {
            if( (pTraverse->lCount + 1) == k )
            {
                ret = pTraverse->data;
                break;
            }
            else if( k > pTraverse->lCount )
            {
                k = k - (pTraverse->lCount + 1);
                pTraverse = pTraverse->right;
            }
            else
            {
                pTraverse = pTraverse->left;
            }
        }
    }

    return ret;
}
int main(void)
{
    int ele[] = { 20, 8, 22, 4, 12, 10, 14 };
    int i;
    node_t* root = NULL;
    root = binary_search_tree(root, ele, ARRAY_SIZE(ele));
    for(i = 1; i <= ARRAY_SIZE(ele); i++)
    {
        printf("\n kth smallest elment for k = %d is %d",
                 i, k_smallest_element(root, i));
    }
}
