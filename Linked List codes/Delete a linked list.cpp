#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node* next;
};
void del(node** head)
{
    node* curr=*head;
    node* next;
    while(curr!=NULL)
    {
        next=curr->next;
        free(curr);
        curr=next;
    }
    *head=NULL;
}
void print(node* n)
{
    if(n==NULL)
        {
            cout<<"Empty\n";
            return ;
        }
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

int main()
{
    node* head=NULL;
    insert_front(&head,1);
    insert_front(&head,2);
    insert_front(&head,3);
    print(head);
    del(&head);
    print(head);
}
