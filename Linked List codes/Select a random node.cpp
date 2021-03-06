#include<iostream>
#include<time.h>
#include<stdlib.h>
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
void random(struct node *head)
{
    if (head == NULL)
       return;
    srand(time(NULL));

    int result = head->data;
    struct node *current = head;
    int n;
    for (n=2; current!=NULL; n++)
    {
        if (rand() % n == 0)
           result = current->data;
        current = current->next;
    }
    cout<<result;
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,1);
    insert_front(&head,2);
    insert_front(&head,3);
    insert_front(&head,4);
    insert_front(&head,5);
    insert_front(&head,6);
    insert_front(&head,7);
    insert_front(&head,8);
    insert_front(&head,9);
    random(head);
}

