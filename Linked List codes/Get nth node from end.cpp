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
void print(node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}
int len_rec(node* head)
{
    if(head==NULL)
        return 0;
    else return 1+len_rec(head->next);
}
void getn_end(node* head,int n)
{
    node*ref,*main;
    ref=main=head;
    int count = 0;
    if(head != NULL)
    {
        while( count < n )
        {
            if(ref == NULL)
            {
                cout<<n<<" is greater than the no. of nodes in list";
            return;
            }
            ref = ref->next;
            count++;
        } /* End of while*/

        while(ref != NULL)
        {
            main = main->next;
            ref  = ref->next;
        }
        cout<<"Node no. "<<n<<" from last is "<<main->data;
    }
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
    getn_end(head,4);
}
