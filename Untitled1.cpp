#include<iostream>
using namespace std;

long mSort(long arr[], long temp[], long left, long right);
long merge(long arr[], long temp[], long left, long mid, long right);

long mergeSort(long arr[], long array_size)
{
    long *temp = new long [array_size];
    return mSort(arr, temp, 0, array_size - 1);
}

long mSort(long arr[], long temp[], long left, long right)
{
    long mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;
        inv_count  = mSort(arr, temp, left, mid);
        inv_count += mSort(arr, temp, mid+1, right);
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

long merge(long arr[], long temp[], long left, long mid, long right)
{
    long i, j, k;
    long inv_count = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return inv_count;
}



int main()
{

    long t;
    cin>>t;
    long l=t;
    while(t--)
    {

        long n,k,i,arr[1000000],j,inv=0,ans,k1;
        cin>>n>>k;
        for(i=0;i<n;i++)
            cin>>arr[i];

        /*for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
            if(arr[i]>arr[j])
                inv++;
        */
        inv=mergeSort(arr,n);
        if(inv>=k)
            ans=inv-k;
        else
        {
            k1=k-inv;
            for(i=0;i<n-1;i++)
                if(arr[i]==arr[i+1])
            {
                ans=0;
            }
            if(k1%2==0)
                ans=0;
            else ans=1;
        }
        cout<<"Case "<<l-t<<": "<<ans<<'\n';
    }
}
