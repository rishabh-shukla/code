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
void ins_sort(node** head,int key)
{
    node* n=*head;
    if(n==NULL)
    {
        n->data=key;
        n->next=NULL;
    }
    node* prev=NULL;
    while(n!=NULL && n->data<key)
    {
        prev=n;
        n=n->next;
    }
    node*s=new node;
    s->data=key;
    prev->next=s;
    s->next=n;
}
int main()
{
    struct node *head=NULL;
    insert_front(&head,6);
    insert_front(&head,4);
    insert_front(&head,3);
    insert_front(&head,2);
    insert_front(&head,1);
    print(head);
    cout<<'\n';
    ins_sort(&head,8);
    print(head);
    cout<<'\n';
    ins_sort(&head,5);
    print(head);

}
