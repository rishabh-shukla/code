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
void split(node* last,node** a,node** b)
{
    node* f=last->next;
    node* s=f;
    do
    {
     f=f->next->next;
     s=s->next;
    }while(f!=last->next);
    while(f->next!=s)
    {
        f=f->next;
    }
    f->next=last->next;
    last->next=s;
    *a=f;
    *b=last;
}
int main()
{
    node* last=NULL;
    last=addEmpty(last,1);
    last=addBegin(last,2);
    last=addEnd(last,3);
    last=addAfter(last,4,2);
    print(last);
    cout<<'\n';
    node* a,*b;
    split(last,&a,&b);
    print(a);
    cout<<'\n';
    print(b);
}

