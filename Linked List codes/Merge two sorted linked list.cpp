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

int main()
{
    struct node * head=NULL,*head2=NULL;
    insert_front(&head,4);
    insert_front(&head,3);
    insert_front(&head,1);
    print(head);
    cout<<'\n';
    insert_front(&head2,8);
    insert_front(&head2,7);
    insert_front(&head2,5);
    insert_front(&head2,2);
    print(head2);
    cout<<'\n';
    node* res=NULL;
    res=merge1(head,head2);
    print(res);
}

