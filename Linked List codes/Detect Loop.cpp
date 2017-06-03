
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
int loop(node* head)
{
    node* fast,*slow;
    fast=slow=head;
    while(fast!=NULL && fast->next!=NULL && slow!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
            return 1;
    }
    return 0;
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,1);
    insert_front(&head,2);
    insert_front(&head,3);
    insert_front(&head,4);
    print(head);
    cout<<'\n';
    head->next->next->next->next = head;
    cout<<loop(head);
}
