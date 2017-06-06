#include<iostream>
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
node* merge1(node* a,node* b)
{
    if(a==NULL && b==NULL)
        return NULL;
    if(a==NULL)
        return (b);
    if(b==NULL)
        return (a);
    node* res=NULL;
    if(a->data < b->data)
    {
        a->next=merge1(a->next,b);
        return a;
    }
    else
    {
        b->next=merge1(a,b->next);
        return b;
    }
}
void split(node* n,node** a,node** b)
{
    struct node* fast;
    struct node* slow;
    if (n==NULL || n->next==NULL)
    {
        *a = n;
        *b= NULL;
    }
    else
    {
    slow = n;
    fast = n->next;

    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }

    *a = n;
    *b= slow->next;
    slow->next = NULL;
    }
}
void mergesort(node** head)
{
    node*n=*head;
    if(n==NULL || n->next==NULL)
        return;
    node*a,*b;
    split(n,&a,&b);
    mergesort(&a);
    mergesort(&b);
    *head=merge1(a,b);
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,1);
    insert_front(&head,2);
    insert_front(&head,3);
    insert_front(&head,4);
    insert_front(&head,7);
    insert_front(&head,9);
    insert_front(&head,6);
    insert_front(&head,5);
    mergesort(&head);
    print(head);
}

