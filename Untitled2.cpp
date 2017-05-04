#include<stdio.h>
long long a[200005],b[200005];
long long ans;

void merge(long long i,long long j)
{
    long long mid=(i+j)/2;
    long long left=i,right=mid+1,k=i,p;
    while(left<=mid&&right<=j)
    {
        if(a[left]>a[right])
        {
            ans=ans+mid-left+1;
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
        merge(i,j);
    }

}




int main()
{
    long long t,n,i,k,l,s;
    scanf("%lld",&t);
    //printf("\n");
    for(s=1;s<=t;s++)
    {
        ans=0;
        scanf("%lld",&n);
        scanf("%lld",&k);
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        merge_sort(1,n);
        printf("Case %lld: ",s);
        if(k>ans)
     {
       l=k-ans;
       if(l%2)
       {
         for(i=2;i<=n;i++)
         {
           if(a[i]==a[i-1])
           {
               printf("0\n");
               break;
           }

         }
         if(i==(n+1))
           printf("1\n");
       }
       else
       {
         printf("0\n");
       }
     }
     else
       printf("%lld\n",ans-k);
    }

    return 0;
}
