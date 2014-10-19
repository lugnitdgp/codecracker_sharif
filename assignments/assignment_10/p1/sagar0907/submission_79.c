long long int r[100005],c[100005],rv[100005],cv[100005];
#include<stdio.h>
int main()
{
    long long int g,w,n,m,i,r1,c1,t,l,p,q,x,y,v,j,h,k;
    scanf("%lld",&g);
    for(w=0;w<g;w++)
    {
       scanf("%lld %lld",&n,&m);
       t=0;l=0;
       for(i=0;i<m;i++)
       {
           scanf("%lld %lld %lld",&x,&y,&v);
            p=-1;
           for(j=0;j<t;j++)
           {
               if(r[j]==x)
               {
                    p=j;
                    break;
               }
           }
           if(p!=-1)
           {
               rv[j]+=v;
           }
           else
           {
                r[t]=x;
                rv[t]=v;
                t++;
           }
            q=-1;
           for(j=0;j<l;j++)
           {
               if(c[j]==y)
               {
                    q=j;
                    break;
               }
           }
           if(q!=-1)
           {
               cv[j]+=v;
           }
           else
           {
                c[l]=y;
                cv[l]=v;
                l++;
           }
       }
       h=0;
       for(i=0;i<t;i++)
       {
           if(rv[i]==h)
           {
               k=0;
           }
           if(rv[i]>h)
           {
               k=1;
                h=rv[i];
                r1=i;
           }
       }
       c1=0;
       for(i=0;i<l;i++)
       {
           if(cv[i]==h)
           {
               k=0;
           }
           if(cv[i]>h)
           {
               k=2;
                h=cv[i];
                c1=i;
           }
       }
       if(k==0)
       printf("Bad luck\n");
       else
       {
           if(k==2)
           {
               i=c1;
               printf("Column %lld\n",c[i]);
           }
           else
           {
               i=r1;
               printf("Row %lld\n",r[i]);
           }
       }
    }
    return 0;
}
