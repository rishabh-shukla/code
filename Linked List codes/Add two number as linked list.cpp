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
struct node *newNode(int data)
{
    struct node *new_node=new node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
node* add(node*a,node*b)
{
    node* res=NULL;
    node* temp,*prev=NULL;
    int carry=0,sum;
    while(a!=NULL || b!=NULL)
    {
        sum = carry + (a? a->data: 0) + (b? b->data: 0);
        carry = (sum >= 10)? 1 : 0;
        sum = sum % 10;
        temp=newNode(sum);
        if(res == NULL)
            res = temp;
        else
            prev->next = temp;
        prev  = temp;
        if (a) a = a->next;
        if (b) b = b->next;
    }
    if(carry>0)
        temp->next=newNode(carry);
        return res;
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,6);
    insert_front(&head,4);
    insert_front(&head,9);
    insert_front(&head,5);
    insert_front(&head,7);
    node* head2=NULL;
    insert_front(&head2,4);
    insert_front(&head2,8);
    node* res=NULL;
    res=add(head,head2);
    print(res);
}

