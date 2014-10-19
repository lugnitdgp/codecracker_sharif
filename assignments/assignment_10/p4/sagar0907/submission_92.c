long long int a[100005];
#include<stdio.h>
int main()
{
    long long int q,w,n,m,i,v,l,r,c,j;
    scanf("%lld",&q);
    for(w=0;w<q;w++)
    {
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(i=1;i<=m;i++)
        {
            scanf("%lld %lld %lld",&v,&l,&r);
            c=0;
            for(j=l;j<=r;j++)
            {
                if(a[j]==v)
                {
                    c++;
                }
            }
            if(c==0)
            printf("NO 0\n");
            else
            printf("YES %lld\n",c);
        }
    }
    return 0;
}

