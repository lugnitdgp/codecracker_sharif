#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
    int t;long long int n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        long long int a[n],diff[n+1];
        for(i=0;i<n;i++)
        {
            diff[i]=0;
        }
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            diff[a[i]]++;
        }
        int count=0;long long int ar[3];
        while(count!=2)
        {
            if(diff[i]!=0)
            {
                ar[count]=i;count++;
            }
            i++;
        }
        printf("%lld\n",ar[1]-ar[0]);
        }
        return 0;
}
