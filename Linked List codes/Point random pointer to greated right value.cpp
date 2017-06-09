#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node* random;
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
    n->random=NULL;
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
node *reverse(node* head)
{
    node* prev=NULL,*curr,*next;
    curr=head;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
node* random_fill(node* head)
{
    head=reverse(head);
    node* max=head;
    node* temp=head->next;
    while(temp!=NULL)
    {
        temp->random=max;
        if(max->data<temp->data)
            max=temp;
        temp=temp->next;
    }
    return reverse(head);
}
void printNextArbitPointers(node *node)
{
    printf("node\tNext Pointer\tArbit Pointer\n");
    while (node!=NULL)
    {
        cout << node->data << "\t\t";

        if (node->next)
            cout << node->next->data << "\t\t";
        else cout << "NULL" << "\t\t";

        if (node->random)
            cout << node->random->data;
        else cout << "NULL";

        cout << endl;
        node = node->next;
    }
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,1);
    insert_front(&head,2);
    insert_front(&head,4);
    insert_front(&head,3);
    insert_front(&head,5);
    head=random_fill(head);
    printNextArbitPointers(head);

}

