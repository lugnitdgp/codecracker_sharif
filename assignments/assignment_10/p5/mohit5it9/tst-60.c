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
        long long int a[n],diff[n];
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        qsort(a,n,sizeof(long long int),compare);
        for(i=0;i<n-1;i++)
        {
            diff[i]=a[i+1]-a[i];
        }
        qsort(diff,n-1,sizeof(long long int),compare);
        printf("%lld\n",diff[0]);
    }
    return 0;
}
