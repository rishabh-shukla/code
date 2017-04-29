#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
class Linear_probing{
	vector<int> v1,v2;
	int N,count;
	public:
	void insert(int);
	void rehashing();
}

void Linear_probing:: insert(int n,vector<int >& v3){
	int h=n%300,i;
	if(v1[h]==-1)
		v1[h]=n;
	else{
		for(i=h+1;i!=h;i++)
		{
			if(v1[i]==-1)
			{
				v1[i]=n;
				break;
			}
			count++;
		}
	}
}

void  Linear_probing::rehashing(void){
	int i,h,j;
	for(i=0;i<N/2;i++)
		v2[i]=-1;
	for(i=0;i<N/2;i++)
	{
		if(v1[i]!=0)
		{
			h=v1[i]%300;
			if(v2[h]==-1)
				v2[h]=n;
			else{
				for(i=h+1;i!=h;i++)					



