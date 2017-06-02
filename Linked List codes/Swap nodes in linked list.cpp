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
void print(node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
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
bool search(node* head,int key)
{
    node* n=new node;
    n=head;
    while(n!=NULL)
    {
        if(n->data==key)
            return 1;
        n=n->next;
    }
    return 0;
}
void swap(node** head,int val1,int val2)
{
    if(val1==val2)
        cout<<"Same value\n";
    node* n=new node;
    n=*head;
    int flag=0;
    node *curr1,*curr2,*prev1,*prev2;
    curr1=*head;
    curr2=*head;
    while(curr1 && curr1->data!=val1)
    {
        prev1=curr1;
        curr1=curr1->next;
    }
    while(curr2 && curr2->data!=val2)
    {
        prev2=curr2;
        curr2=curr2->next;
    }
    if(curr1==NULL || curr2==NULL)
        cout<<"NULL\n";

    if(prev1!=NULL)
        prev1->next=curr2;
    else
        *head=curr2;

    if(prev2!=NULL)
        prev2->next=curr1;
    else *head=curr1;

    node *temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next  = temp;
    //n=*head;


}
int main()
{
    struct node * head=NULL;
    insert_front(&head,10);
    insert_front(&head,15);
    insert_front(&head,12);
    insert_front(&head,13);
    insert_front(&head,20);
    insert_front(&head,14);
    print(head);
    cout<<'\n';
    swap(&head,12,20);
    print(head);

}
