#include<iostream>
#include<stdio.h>
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

bool isSumSorted(struct node *headA, struct node *headB,
                 struct node *headC, int givenNumber)
{
    struct node *a = headA;
    while (a != NULL)
    {
        struct node *b = headB;
        struct node *c = headC;
        while (b != NULL && c != NULL)
        {
            int sum = a->data + b->data + c->data;
            if (sum == givenNumber)
            {
               printf ("Triplet Found: %d %d %d ", a->data,
                                         b->data, c->data);
               return true;
            }
            else if (sum < givenNumber)
                b = b->next;
            else // If sum is greater, look for smaller values in c
                c = c->next;
        }
        a = a->next;  // Move ahead in list a
    }

    printf ("No such triplet");
    return false;
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,20);
    insert_front(&head,4);
    insert_front(&head,15);
    insert_front(&head,20);
    node*b=NULL,*c=NULL;
    insert_front(&b,10);
    insert_front(&b,9);
    insert_front(&b,4);
    insert_front(&b,2);
    insert_front(&c,1);
    insert_front(&c,2);
    insert_front(&c,4);
    insert_front(&c,8);
    isSumSorted(head,b,c,25);
}

