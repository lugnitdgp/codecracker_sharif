#include<stdio.h>


int main()
{
    int t,n,a[10000],i,j,sum,avg,m,mi,flag,count;
    scanf("%d",&t);
    while(t--)
    {
        avg=0;
        count=0;
        flag=1;
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        for(i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
                flag=0;
        }

        if(sum%n==0&&!flag)
        {
            sum=sum/n;
            for(i=0;i<n;i++)
                if(a[i]>sum)
                    avg++;
                avg--;
            while(!flag){
                m=0;
                for(i=0;i<n;i++)
                {
                    if(m<a[i])
                    {
                        m=a[i];
                        mi=i;
                    }
                }
            for(i=mi-1;i>=0;i--)
            {
                if(a[i]<sum)
                {
                    a[i]++;
                    a[mi]--;
                    break;
                }
            }
            for(i=mi+1;i<n;i++)
            {
                if(a[i]<sum)
                {
                    a[i]++;
                    a[mi]--;
                    break;
                }
            }
        flag=1;
        for(i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
                flag=0;
        }
        count++;
        }
        printf("%d\n",(count-avg));
        }
        else if(sum%n!=0)
            printf("ANGRY\n");
    }
    return 0;
}
