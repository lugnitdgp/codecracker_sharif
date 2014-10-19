//write your code here
#include<stdio.h>
int main()
    {
        long long int q,w,n,i,j,d,m,a[100005];
        scanf("%lld",&q);
        for(w=0;w<q;w++)
        {
            scanf("%lld",&n);
            m=1000000005;
            for(i=0;i<n;i++)
            {
                scanf("%lld",&a[i]);
            }
            for(i=0;i<n;i++)
            {
                for(j=i+1;j<n;j++)
                {
                    d=a[i]-a[j];
                    if(d<0)
                    d*=-1;
                    if(d<m)
                    m=d;
                }
            }
            printf("%lld\n",m);
        }
        return 0;
    }


