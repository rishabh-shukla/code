#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
};
void push(node** head,int data)
{
    node* n=new node;
    n->data=data;
    n->next=*head;
    n->prev=NULL;
    if((*head)!=NULL)
        (*head)->prev=n;
    (*head)=n;
}
void insertAfter(node* prev,int data)
{
    if(prev==NULL)
    {
        cout<<"Not possible\n";
        return;
    }
    node* n=new node;
    n->data=data;
    n->prev=prev;
    n->next=prev->next;
    prev->next=n;
    if(n->next!=NULL)
        n->next->prev=n;
}
void append(node** head,int data)
{
    node* n=new node;
    node* last=*head;
    n->data=data;
    n->next=NULL;
    if(*head==NULL)
    {
        n->prev=NULL;
        *head=n;
        return;
    }
    while(last->next!=NULL)
        last=last->next;
    last->next=n;
    n->prev=last;
    return;
}
void print(node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    node* head=NULL;
    append(&head,1);
    push(&head,2);
    push(&head,3);
    append(&head,4);
    insertAfter(head->next,5);
    print(head);

}
