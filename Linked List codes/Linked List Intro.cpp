#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
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
void insert_back(node**head,int data)
{
    struct node* n=*head;
    struct node* n1=new node;
    n1->data=data;
    n1->next=NULL;

    while(n->next!=NULL)
    {
        n=n->next;
    }
    n->next=n1;
}
void delete_node(node** head,int key)
{
    struct node* n=new node;
    n=*head;
    if(n!=NULL &&n->data==key)
    {
        *head=n->next;
        return;
    }
    while(n->next!=NULL && n->next->data!=key)
        n=n->next;
    n->next=n->next->next;

}
void delete_pos(node** head,int pos)
{
    struct node* n=*head;
    int count=0;
    if(pos==0)
        *head=n->next;
    else
    {
        while(n!=NULL)
        {
            n=n->next;
            count++;
            if(count==pos)
                break;
        }
        n->next=n->next->next;
    }
}
int main()
{
    struct node* head=new node,*n1=new node,*n2=new node;
    head->data=1;
    head->next=n1;
    n1->data=2;
    n1->next=n2;
    n2->data=3;
    n2->next=NULL;
    print(head);
    insert_front(&head,4);
    cout<<'\n';
    print(head);
    cout<<'\n';
    insert_back(&head,5);
    print(head);
    cout<<'\n';
    delete_node(&head,4);
    print(head);
    cout<<'\n';
    delete_pos(&head,1);
    print(head);

}
