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
bool check(node* a,node* b)
{

    while(a!=NULL && b!=NULL)
    {
        if(a->data!=b->data)
            return false;
        a=a->next;
        b=b->next;
    }
    if(a==NULL && b==NULL)
        return 1;
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,1);
    insert_front(&head,2);
    insert_front(&head,3);
    insert_front(&head,4);
    insert_front(&head,1);
    node* head2=NULL;
    insert_front(&head2,1);
    insert_front(&head2,2);
    insert_front(&head2,3);
    insert_front(&head2,4);
    insert_front(&head2,1);
    cout<<check(head,head2);
}
