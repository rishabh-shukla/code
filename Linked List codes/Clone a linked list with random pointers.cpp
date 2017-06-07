#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node* arb;
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
node* clone(node* head)
{
    node*curr=head,*temp;
    while(curr)
    {
        temp=curr->next;
        curr->next=new node;
        curr->next->data=curr->data;
        curr->next->next=temp;
        curr=temp;
    }
    curr=head;
    while(curr)
    {
        curr->next->arb=curr->arb->next;
        curr=curr->next?curr->next->next:curr->next;
    }

    node* original=head,*copy=head->next;
    temp=copy;
    while(original && temp)
    {
        original->next =
         original->next? original->next->next : original->next;

        copy->next = copy->next?copy->next->next:copy->next;
        original = original->next;
        copy = copy->next;
    }
    return temp;
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,5);
    insert_front(&head,4);
    insert_front(&head,3);
    insert_front(&head,2);
    insert_front(&head,1);
    head->arb=head->next->next;
    head->next->arb=head;
    head->arb->arb=head->arb->next->next;
    head->arb->arb->arb=head->next;
    head->arb->next->arb=head->next->next;
    print(head);
    cout<<'\n';
    node* c= clone(head);
    print(c);
}

