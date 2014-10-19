#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
struct data
{
    int r;
    char s[60];
};
struct data1
{
    int y;
    int z;
};
bool myfunc(struct data,struct data);
bool myfunc1(struct data1,struct data1);
int main()
{
    int t,n,m,i,max,temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        struct data v[m];
        struct data1 u[n];
        for(i=0;i<m;i++)
        {
            scanf("%d",&v[i].r);
            gets(v[i].s);
        }
        for(i=0;i<n;i++)
        scanf("%d%d",&u[i].y,&u[i].z);

        sort(v,v+m,myfunc);
        sort(u,u+n,myfunc1);

        for(i=0;i<n;i++)
        {
            printf("%d %d\n",u[i].y,u[i].z);
        }

        max=u[0].z;temp=0;

        for(i=1;i<n;i++)
        {
            if((u[i].y==u[i-1].y))
            {
                if(u[i].z>max)
            {
                //printf("max=%d\n",max);
                max=u[i].z;
            }
            }
            else
            {
                //printf("adsad\n");
                printf("%s",v[temp].s);
                printf(" %d\n",max);
                temp++;
                max=u[i].z;
            }
        }
        printf("%s",v[temp].s);
        printf(" %d\n",max);
    }
}
bool myfunc(struct data i,struct data j)
{
    if(i.r<j.r)
    return true;
    else
    return false;
}
bool myfunc1(struct data1 i,struct data1 j)
{
    if(i.y<j.y)
    return true;
    else
    return false;
}
