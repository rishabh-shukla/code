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
void rotate(node**head ,int k)
{
    if(k==0)
        return;
    node* curr=*head;
    int c=1;
    while(c<k && curr!=NULL)
    {
        curr=curr->next;
        c++;
    }
    if(curr==NULL)
        return;
    node *n=curr;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=*head;
    *head=n->next;
    n->next=NULL;
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,1);
    insert_front(&head,2);
    insert_front(&head,3);
    insert_front(&head,4);
    insert_front(&head,5);
    insert_front(&head,6);
    insert_front(&head,7);
    rotate(&head,3);
    print(head);
}

