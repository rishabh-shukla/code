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
node* reverse(node*head,int k)
{
    node *curr=head,*prev=NULL,*next=NULL;
    int c=0;
    while(curr!=NULL && c<k)
    {
        next  = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        c++;
    }
    if(next!=NULL)
        head->next=reverse(next,k);
    return prev;
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
    insert_front(&head,8);
    insert_front(&head,9);
    head=reverse(head,3);
    print(head);
}

