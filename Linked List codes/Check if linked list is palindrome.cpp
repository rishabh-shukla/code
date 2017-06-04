
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
bool ispal_util(node** left,node* right)
{
    if(right==NULL)
        return true;

    bool isp=ispal_util(left,right->next);
    if(isp==false)
        return false;
    bool isp1= (right->data==(*left)->data);

    (*left)=(*left)->next;
    return isp1;
}
bool ispal(node* head)
{
    return ispal_util(&head,head);
}
int main()
{
    struct node * head=NULL;
    insert_front(&head,1);
    insert_front(&head,2);
    insert_front(&head,3);
    insert_front(&head,2);
    insert_front(&head,1);
    cout<<ispal(head);
}
