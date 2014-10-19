#include<stdio.h>

int main()
{
    int max=10001;
    int t,t1,i,j;
    int a[10001];

    for(i=2;i<max;i++)
    a[i]=i;

    for(i=2;i<max;i++)
    {
        if(a[i]==i)
        {
            for(j=i;j<max;j+=i)
            a[j]-=a[j]/i;
        }
    }
    scanf("%d",&t);
    int z[t];
    t1=t;
    for(i=0;i<t;i++)
    {
        scanf("%d",&z[i]);
    }
    for(i=0;i<t;i++)
    {
        printf("%d\n",a[z[i]]);
    }
    return(0);

}
