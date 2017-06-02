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
int main()
{
    struct node * head=NULL;
    insert_front(&head,1);
    insert_front(&head,2);
    insert_front(&head,3);
    insert_front(&head,4);
    insert_front(&head,1);
    cout<<search(head,0)<<'\n';
    cout<<search(head,2)<<'\n';
    cout<<search(head,1)<<'\n';
}
