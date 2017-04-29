#include<iostream>
#include<string.h>
using namespace std;
//Defining a class
class student
{	private:
	//private data members
	char first[20],last[20];
	
	int sub[5];
	public:
	//public data members
	char roll_no[11];
	void SetStudRec(student&);
	void GetIndStudRec(student&);
	void GetAllStudRec( student*,int );
	void GetAvgMarks(student*,int ,int );
}
Stud;
//Function to input data
void student:: SetStudRec(student &Stud)
{	cout<<"Enter your name\n";
	cin>>Stud.first>>Stud.last;

	B:
	
	cout<<"Enter your roll no.\n";
	cin>>Stud.roll_no;
	int i;
	if((Stud.roll_no[0]!='C')||(Stud.roll_no[1]!='S')||(Stud.roll_no[2]!='1')||(Stud.roll_no[3]!='5')||(Stud.roll_no[4]!='B'))
		{
			cout<<"Wrong Entry\n";
			goto B;
		}
	for(i=5;i<8;i++)
	if((Stud.roll_no[i]-'0'<0)||(Stud.roll_no[i]-'0'>9))
		{	
			cout<<"Wrong entry\n";
			goto B;
		}	
	cout<<"Enter the marks of 5 subjects\n";
	
	for(i=0;i<5;i++)
		cin>>Stud.sub[i];	
}
//Function to show one set of data
void student:: GetIndStudRec(student &Stud)
{
	cout<<"Name\n";
	cout<<Stud.first<<" "<<Stud.last;
	cout<<"\nRoll no.\n";
	cout<<Stud.roll_no;
	cout<<"\nMarks of 5 subjects\n";
	int i;
	for(i=0;i<5;i++)
		cout<<Stud.sub[i]<<" ";
		cout<<"\n\n\n";
}
//Function to show all sets of data
void student::GetAllStudRec( student *Stud,int n)
{
	int i;
	for(i=0;i<n;i++)
		GetIndStudRec(Stud[i]);

}
//Function to find average marks in a subject
void student::GetAvgMarks(student *Stud,int n,int sub_no)
{
	int i;
	float avg=0;
	for(i=0;i<n;i++)
		avg+=Stud[i].sub[sub_no+-1];
	avg=avg/n;

	cout<<avg<<'\n';
}
//Main program
int main()
{	
	class student Stud[10];
	int a,i,s,n,flag=0;
	char roll[11];
	A:
	cout<<"1.Set student record\n"<<"2.Get individual student recortd\n"<<"3.Get All student's record\n"<<"4.Get Average of a subject\n"<<"5.Exit\n";
	cin>>a;
	if(a==1)
	{	cout<<"Enter number of students\n";
		cin>>n;
		for(i=0;i<n;i++)
			Stud[i].SetStudRec(Stud[i]);
		goto A;
	}
	

	if(a==2)
	{
		cout<<"Enter the roll no.\n";
		cin>>roll;
		for(i=0;i<n;i++)
			if(strcmp(Stud[i].roll_no,roll)==0)
			{	flag=1;
				Stud[i].GetIndStudRec(Stud[i]);
			}
		if(flag==0)
			cout<<"No data exist\n";
		goto A;
	}

	if(a==3)
	{
		Stud[i].GetAllStudRec(Stud,n);
		goto A;
	}

	if(a==4)
	{
		cout<<"Enter the subject index\n";
		cin>>s;
		if((s<1)||(s>5))
		{
			cout<<"Wrong entry\n\n";
			
		}
		else
		Stud[i].GetAvgMarks(Stud,n,s);
		goto A;
	}
	
	if(a==5)
		return 0;
}

	

