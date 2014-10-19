//write your code here
#include<stdio.h>
int main()
{
    long long int n,a,b,c,e;
    double d;
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        d=((a+c)/2.0)-b;
        if(d<0)
        d*=-1;
        e=d;
        if(d>e)
        printf("%.2lf\n",d);
        else
        printf("%lld\n",e);
    }
    return 0;
}
