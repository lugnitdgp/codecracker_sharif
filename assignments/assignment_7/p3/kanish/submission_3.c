#include<stdio.h>
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
float sum=0,x1=0;
int a,c=0;
float x=0;
scanf("%d",&a);
float n[a];
int i,xx;
for(i=0;i<a;i++)
{
c++;
scanf("%f",&n[i]);
if(i>0)
if(n[i-1]==n[i])
{
c++;
if(c==a)
printf("0\n");
return 0;
}
sum+=n[i];
}
x=(float)(sum/6);
xx=(int)(x)*6;
//printf("%f",x);
if(xx==sum)
printf("%.0f\n",x-1);
else
printf("ANGRY\n");

}
return 0;
}
