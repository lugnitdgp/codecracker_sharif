//write your code here
#include<stdio.h>
#include<algorithm>
using namespace std;
struct data
{
    int y,z,x;
};
struct data1
{
    int y,z,x;
};
bool myfunc(struct data ,struct data );
bool myfunc1(struct data1 ,struct data1 );
int main()
{
    int t,n,m,i,j,max,maxr,flag,tmax,in,ans1,f1,ans2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        struct data v[m];
        struct data1 v1[m];
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&v[i].y,&v[i].z,&v[i].x);
            v1[i].y=v[i].y;
            v1[i].z=v[i].z;
            v1[i].x=v[i].x;
        }
        sort(v,v+m,myfunc);
        sort(v1,v1+m,myfunc1);
        j=1;
        max=0;
        maxr=0;flag=0;tmax=0;in=0;
        for(i=0;i<m;i++)
        {
            if(i==0)
            tmax+=v[i].x;
            else if((v[i].y==v[i-1].y))
            {
                tmax+=v[i].x;
            }
            else
            {
              //  printf("row=%d\n",tmax);
                if(tmax==max)
                flag=1;
                if(tmax>max)
                {
                    flag=0;
                    max=tmax;
                    in=v[i-1].y;

                }
                tmax=v[i].x;
            }
        }
        maxr=in;ans1=max;f1=flag;

        flag=0;tmax=0;in=0;max=0;
        for(i=0;i<m;i++)
        {
            if(i==0)
            tmax+=v1[i].x;
            else if((v1[i].z==v1[i-1].z))
            {
                tmax+=v1[i].x;
            }
            else
            {
                if(tmax==max)
                flag=1;
                if(tmax>max)
                {
                    flag=0;
                    max=tmax;
                    in=v1[i-1].z;
                    //tmax=v1[i].x;
                }
                tmax=v[i].x;
            }
        }
        ans2=max;
        if(ans1==ans2)
        printf("Bad luck\n");
        else if(ans1>ans2)
        {
            if(f1==0)
            printf("Row %d\n",maxr);
            else
            printf("Bad luck\n");
        }
        else
        {
            if(flag==0)
            printf("Column %d\n",in);
            else
            printf("Bad luck\n");
        }

    }
    return(0);
}
bool myfunc(struct data i,struct data j)
{
    if(i.y<j.y)
    return true;
    else
    return false;
}
bool myfunc1(struct data1 i,struct data1 j)
{
    if(i.z<j.z)
    return true;
    else
    return false;
}
