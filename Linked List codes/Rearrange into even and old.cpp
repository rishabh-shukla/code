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
node *rearrangeEvenOdd(node *head)
{
    // Corner case
    if (head == NULL)
        return NULL;

    // Initialize first nodes of even and
    // odd lists
    node *odd = head;
    node *even = head->next;

    // Remember the first node of even list so
    // that we can connect the even list at the
    // end of odd list.
    node *evenFirst = even;

    while (1)
    {
        // If there are no more nodes, then connect
        // first node of even list to the last node
        // of odd list
        if (!odd || !even || !(even->next))
        {
            odd->next = evenFirst;
            break;
        }

        // Connecting odd nodes
        odd->next = even->next;
        odd = even->next;

        // If there are NO more even nodes after
        // current odd.
        if (odd->next == NULL)
        {
            even->next = NULL;
            odd->next = evenFirst;
            break;
        }

        // Connecting even nodes
        even->next = odd->next;
        even = odd->next;
    }

    return head;
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

    head=rearrangeEvenOdd(head);
    print(head);
}


