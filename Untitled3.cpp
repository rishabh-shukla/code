#include<iostream>
using namespace std;
long long a[100005],b[100005];
long long inv;
void merge1(long long i,long long j)
{
    long long mid=(i+j)/2;
    long long left=i,right=mid+1,k=i,p;
    while(left<=mid&&right<=j)
    {
        if(a[left]>a[right])
        {
            inv=inv+mid-left+1;
            b[k++]=a[right++];
        }
        else
            b[k++]=a[left++];
    }

    if(left>mid)
    {
        while(right<=j)
           b[k++]=a[right++];
    }

    else if(right>j)
    {
        while(left<=mid)
            b[k++]=a[left++];
    }

    for(p=i;p<=j;p++)
        a[p]=b[p];

}

void merge_sort(long long i,long long j)
{
    long long mid;
    if(i<j)
    {
        mid=(i+j)/2;
        merge_sort(i,mid);
        merge_sort(mid+1,j);
        merge1(i,j);
    }

}



int main()
{

    long long int t,l;
    cin>>t;
    l=t;
    while(t--)
    {
        inv=0;
        long long int n,k,i,j,ans,k1;
        cin>>n>>k;
        for(i=1;i<=n;i++)
            cin>>a[i];

        /*for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
            if(a[i]>a[j])
                inv++;
        */
        merge_sort(1,n);


            if(k>inv)
        {
            k1=k-inv;
            if(k1%2)
            {

                for(i=1;i<n;i++)
                  {
                    if(a[i]==a[i+1])
                    {
                        ans=0;
                    }
                  }
                if(i==n)
                    ans=1;

            }

            else ans=0;
        }
        else ans=inv-k;
        cout<<"Case "<<l-t<<": "<<ans<<'\n';
    }
}
