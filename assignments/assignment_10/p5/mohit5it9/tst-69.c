#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int t;
    long long int n,i,no;
    long long int diff[100000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0;i<100000;i++)
        {
            diff[i]=0;
        }
        for(i=0;i<n;i++)
        {
            scanf("%lld",&no);
            diff[no]++;
        }
        int count=0;int ar[10];
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
