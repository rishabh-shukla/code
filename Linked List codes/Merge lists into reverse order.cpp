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
node* sortedmerge(node*a,node*b)
{
    if(a==NULL && b==NULL)
        return NULL;
    node* res=NULL;
    while(a && b)
    {
        if(a->data<=b->data)
            {
                insert_front(&res,a->data);
                a=a->next;
            }
        else
            {
                insert_front(&res,b->data);
                b=b->next;
            }
    }
    while(a!=NULL)
        {
            insert_front(&res,a->data);
            a=a->next;
        }
    while(b!=NULL)
        {
            insert_front(&res,b->data);
            b=b->next;
        }
    return res;
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,5);
    insert_front(&head,4);
    insert_front(&head,3);
    insert_front(&head,2);
    insert_front(&head,1);
    node* head2=NULL;
    insert_front(&head2,50);
    insert_front(&head2,40);
    insert_front(&head2,30);
    insert_front(&head2,20);
    insert_front(&head2,10);
    node* res=sortedmerge(head,head2);
    print(res);
}

