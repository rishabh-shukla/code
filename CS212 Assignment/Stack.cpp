# include<iostream>
using namespace std;
# define SIZE 20
int n;
//Defining class
class Stack
{	//private data members
	private:
	int a[SIZE];
	int top; // Top of Stack
	//public data members	
	public:
	Stack();
	void push(int);
	int pop();
	int isempty();
	int isfull();
	int peep();		
	int show();
}
;

//constructor of class Stack
Stack::Stack()
{	
	
	cout<<"Enter the size of stack\n";
	cin>>n;
	top=0; //Initialize Top of Stack
}

//isempty function
int Stack::isempty()
{
	return (top==0?1:0);
}


//push function
void Stack::push(int i)
{
	if(top>=n)
		cout<<"Stack is full\n";
	else
	{
		cout<<"Pushing "<<i<<endl;
		a[top]=i;
		top++;
	}
}

//show all elements
int Stack::show()
{
	if(isempty()==1)
		cout<<"Stack is empty!\n";
	else
	{
		int j;
		for(j=top-1;j>-1;j--)
		cout<<a[j]<<'\n';
	}
	return 0;

}

//popping function
int Stack::pop()
{
	if(!isempty())
	{
		cout<<"Popping "<<a[top-1]<<endl;
		return(a[--top]);
	}
	else
	{
		cout<<"Stack is empty!\n";
	}
	return 0;
}

//show the top element
int Stack::peep()
{
	if(!isempty())
	{
		cout<<"Top is "<<a[top-1]<<endl;
		return 0;
	}
	else
	{
		cout<<"Stack is empty!\n";
	}
	return 0;
}

//main function
int main()
{

	Stack s;
	int a,i;
	A:
	cout<<"1.Push an item\n2.Pop an item\n3.Peep into the stack\n4.Show the elements\n5.Exit\n";
	cin>>a;

	if(a==1)
	{
		cout<<"Enter the element\n";
		cin>>i;
		s.push(i);
		goto A;
	}
	
	if(a==2)
	{
		int b=s.pop();
		goto A;
	}

	if(a==3)
	{
		int b=s.peep();
		goto A;
	}

	if(a==4)
	{
		int b=s.show();
		goto A;
	}

	return 0;

}

