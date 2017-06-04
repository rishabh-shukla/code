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
int intersect(node* head,node* head2)
{
    node* n= new node;
    n=head;
    int c1=0,c2=0;
    while(n!=NULL)
    {
        c1++;
        n=n->next;
    }
    n=head2;
    while(n!=NULL)
    {
        c2++;
        n=n->next;
    }
    if(c1>c2)
    {
        node*n1=head;
        node*n2=head2;
        int d=c1-c2;
        for(int i=0;i<d;i++)
            n1=n1->next;
        while(n1!=NULL && n2!=NULL)
        {
            if(n1==n2)
                return n1->data;
            n1=n1->next;
            n2=n2->next;
        }
    }
    else
    {
        node*n1=head;
        node*n2=head2;
        int d=c2-c1;
        for(int i=0;i<d;i++)
            n2=n2->next;
        while(n1!=NULL && n2!=NULL)
        {
            if(n1==n2)
                return n1->data;
            n1=n1->next;
            n2=n2->next;
        }
    }
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,1);
    insert_front(&head,2);
    insert_front(&head,3);
    insert_front(&head,4);
    insert_front(&head,5);
    node* head2=NULL;
    insert_front(&head2,9);
    insert_front(&head2,7);
    head2->next->next=head->next->next->next;
    print(head);
    cout<<'\n';
    print(head2);
    cout<<'\n';
    cout<<intersect(head,head2);
}

