#include <iostream>
#include<string.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		string s,c;
		cin>>s;
		int i=0,j;
		while(i<s.length())
		{
			if(s[i]=='C' && s[i+1]=='C')
				s[i]='0';
				if(s[i]=='E' && s[i+1]=='E')
				s[i]='0';
				if(s[i]=='S' && s[i+1]=='S')
				s[i]='0';
				i++;
		}
		i=0,j=0;
		while(i<s.length())
            {
                if(s[i]!='0')
                c+=s[i];
                i++;
            }

        //cout<<c;
		if(c=="CES" ||c=="C"||c=="E"||c=="S"||c=="CE"||c=="ES"||c=="CS")
			cout<<"yes\n";
			else cout<<"no\n";
	}
	return 0;
}
