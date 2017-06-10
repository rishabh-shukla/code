#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* addEmpty(node* last,int data)
{
    if(last!=NULL)
        return last;
    last=new node;
    last->data=data;
    last->next=last;
    return last;
}
node* addBegin(node* last,int data)
{
    if(last==NULL)
        return addEmpty(last,data);
    node* t=new node;
    t->data=data;
    t->next=last->next;
    last->next=t;
    return last;
}
node* addEnd(node* last,int data)
{
    if(last==NULL)
        return addEmpty(last,data);
    node* t=new node;
    t->data=data;
    t->next=last->next;
    last->next=t;
    last=t;
    return last;
}
node* addAfter(node* last,int data,int item)
{
    if(last==NULL)
        return NULL;
    node* t,*p;
    p=last->next;
    do
    {
        if(p->data==item)
        {
            t=new node;
            t->data=data;
            t->next=p->next;
            p->next=t;
            if(p==last)
                last=t;
            return last;
        }
        p=p->next;
    } while(p!=last->next);
    cout<<"item not present\n";
    return last;
}
void print(node* last)
{
    if(last==NULL)
        {
            cout<<"Empty list\n";
            return;
        }
    node* n=last->next;
    do
    {
      cout<<n->data<<' ';
      n=n->next;
    }while(n!=last->next);
}
node* sortedInsert(node* last,int data)
{
    node* n=new node;
    n->data=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
        return last;
    }
    else if(last->next->data>=n->data)
    {
        n->next=last->next;
        last->next=n;
        return last;
    }
    else
    {
        node* t=last->next;
        while(t->next!=last->next &&t->next->data<n->data)
                t=t->next;
        n->next=t->next;
        t->next=n;
        return last;
    }
}
int main()
{
    node* last=NULL;
    last=addEmpty(last,3);
    last=addBegin(last,4);
    last=addEnd(last,2);
    last=addAfter(last,1,2);
    print(last);
    cout<<'\n';
    last=sortedInsert(last,3);
    print(last);
}

