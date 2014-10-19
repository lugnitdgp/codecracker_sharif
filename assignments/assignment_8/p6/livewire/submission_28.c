//write your code here
#include<stdio.h>

int main()
{
    long long int n,k,b,i,j,t,z;
    scanf("%lld",&t);
    long long int a[t][2];
    for(i=0;i<t;i++)
    scanf("%lld%lld",&a[i][0],&a[i][1]);
    //scanf("%lld%lld",&a,&b);
    long long int count[t];
    //printf("scas\n");
    for(z=0;z<t;z++)

    {
        count[z]=0;
        for(i=a[z][0]+1;i<a[z][1];i++)
        {
        for(j=a[z][0]+1;j<a[z][1];j++)
        {
            if(((i*j)-a[z][0])%((i-a[z][0])*(j-a[z][0]))==0)
            count[z]+=1;

        }
    }
    }
    for(i=0;i<t;i++)
    printf("%lld\n",count[i]);
    return 0;
}
