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
void zigZagList(node *head)
{
    bool flag = true;
    node* current = head;
    while (current->next != NULL)
    {
        if (flag)
        {
            if (current->data > current->next->data)
                swap(current->data, current->next->data);
        }
        else
        {
            if (current->data < current->next->data)
                swap(current->data, current->next->data);
        }

        current = current->next;
        flag = !flag;
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
    insert_front(&head,6);
    insert_front(&head,7);
    zigZagList(head);
    print(head);
}

