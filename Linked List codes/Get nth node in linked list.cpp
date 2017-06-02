
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
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
int getn(node* head,int n)
{
    if(head==NULL)
        return -1;
    if(n==0)
        return head->data;
    return getn(head->next,n-1);
}
void print(node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,1);
    insert_front(&head,2);
    insert_front(&head,3);
    insert_front(&head,4);
    insert_front(&head,1);
    print(head);
    cout<<'\n';
    cout<<getn(head,3);
}
