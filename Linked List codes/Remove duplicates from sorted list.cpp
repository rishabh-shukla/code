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
void remove_duplicates(node* head)
{
    if(head==NULL)
        return;
    node* n=head;
    node* n1;
    while(n->next!=NULL)
    {
        if(n->data==n->next->data)
        {
            n1=n->next->next;
            free(n->next);
            n->next=n1;
        }
        else
            n=n->next;
    }
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,5);
    insert_front(&head,4);
    insert_front(&head,4);
    insert_front(&head,2);
    insert_front(&head,1);
    print(head);
    cout<<'\n';
    remove_duplicates(head);
    print(head);
}

