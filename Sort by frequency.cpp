#include <bits/stdc++.h>
using namespace std;
typedef multimap<int, int> MapType;

int main()
{
    int a[] = {5,8,3,8,5,5,8,3,2,3,5,3};
		int N = sizeof(a)/sizeof(a[0]);

    map<int,int> mp;

    for(int i=0;i<N;i++)
    {
        if(mp.find(a[i])!=mp.end())
            mp[a[i]]++;
        else
            mp[a[i]]=1;
    }

		multimap<int,int> mp2;

    map<int,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
      mp2.insert(MapType::value_type(it->second,it->first));

	  map<int,int>::reverse_iterator itr;
    for(itr=mp2.rbegin();itr!=mp2.rend();itr++)
    {

        for(int i=0;i<itr->first;i++)
            cout<<itr->second<<" ";
    }

    return 0;
}
