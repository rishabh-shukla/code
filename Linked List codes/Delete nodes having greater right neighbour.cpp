#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node* next;
};
void print(node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}
void insert_front(node** head,int data)
{
    struct node* n=new node;
    n->data=data;
    n->next=*head;
    *head=n;
}
int len(node* head)
{
    node* n=new node;
    n=head;
    int l=0;
    while(n!=NULL)
    {
        l++;
        n=n->next;
    }
    return l;
}
int len_rec(node* head)
{
    if(head==NULL)
        return 0;
    else return 1+len_rec(head->next);
}
void reverseList(struct node **headref)
{
     struct node *current = *headref;
     struct node *prev = NULL;
     struct node *next;
     while (current != NULL)
     {
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
     }
     *headref = prev;
}
void del(node* head)
{
    struct node *current = head;

    struct node *maxnode = head;
    struct node *temp;

    while (current != NULL && current->next != NULL)
    {
     if(current->next->data < maxnode->data)
     {
         temp = current->next;
         current->next = temp->next;
         free(temp);
     }
    else
     {
         current = current->next;
         maxnode = current;
     }
    }
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,3);
    insert_front(&head,2);
    insert_front(&head,6);
    insert_front(&head,5);
    insert_front(&head,11);
    insert_front(&head,10);
    insert_front(&head,15);
    insert_front(&head,12);
    reverseList(&head);
    del(head);
    reverseList(&head);
    print(head);
}
