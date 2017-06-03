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
void reverseUtil(node *curr, node *prev, node **head)
{
    if (!curr->next)
    {
        *head = curr;
        curr->next = prev;
        return;
    }
    node *next = curr->next;
    curr->next = prev;
    reverseUtil(next, curr, head);
}
void reverse(node **head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,1);
    insert_front(&head,2);
    insert_front(&head,3);
    insert_front(&head,4);
    insert_front(&head,1);
    print(head);
    cout<<'\n';
    reverse(&head);
    print(head);
}


