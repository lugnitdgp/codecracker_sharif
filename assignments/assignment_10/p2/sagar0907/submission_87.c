#include<stdio.h>
int main()
{
    long long int q,w,n,m,i,rn[1005],ron[1005],temp,mark[1005],roll,p,j,marks,name[1005];
    char nm[1005][45],x;
    scanf("%lld",&q);
    for(w=0;w<q;w++)
    {
        scanf("%lld %lld",&m,&n);
        for(i=0;i<m;i++)
        {
            scanf("%lld",&rn[i]);
            ron[i]=rn[i];
            x=getchar();
            gets(nm[i]);
            mark[i]=0;
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<m-i-1;j++)
            {
                if(ron[j]>ron[j+1])
                {
                    temp=ron[j];
                    ron[j]=ron[j+1];
                    ron[j+1]=temp;
                }
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                if(ron[i]==rn[j])
                name[i]=j;
            }
        }
        for(i=0;i<n;i++)
        {
            scanf("%lld",&roll);
            for(j=0;j<m;j++)
            {
                if(roll==ron[j])
                p=j;
            }
            scanf("%lld",&marks);
            if(marks>mark[p])
            mark[p]=marks;
        }
        for(i=0;i<m;i++)
        {
            j=name[i];
            printf("%s ",nm[j]);
            printf("%lld\n",mark[i]);
        }
    }
    return 0;
}
