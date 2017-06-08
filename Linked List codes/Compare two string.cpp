#include<iostream>
using namespace std;
struct node
{
    char data;
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
void insert_front(node** head,char data)
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
int compare(node* a,node* b)
{
    while(a && b && a->data==b->data)
    {
        a=a->next;
        b=b->next;
    }
    if(a && b)
        return (a->data>b->data)?1:-1;
    if(a && !b)
        return 1;
    if(b && !a)
        return -1;
    return 0;
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,'c');
    insert_front(&head,'h');
    insert_front(&head,'a');
    insert_front(&head,'r');
    node* head2=NULL;
    insert_front(&head2,'c');
    insert_front(&head2,'h');
    insert_front(&head2,'a');
    insert_front(&head2,'r');
    cout<<compare(head,head2);
}

