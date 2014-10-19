#include<stdio.h>
#define MAX 10000

int lonlen(int ar[],int size)
{
int i,j,max=0,len=0;
if(ar[0]>0)
{
len++;
for(j=1;j<size;j++)
{
for(i=j;i<size;i++)
{
if(i%2!=0&&ar[i]<0)
len++;
else if(i%2==0&&ar[i]>0)
len++;
else
{
if(max<len)
max=len;
len=0;
j=i;
break;
}
}
}
}
else
{
len++;
for(j=1;j<size;j++)
{
for(i=j;i<size;i++)
{
if(i%2!=0&&ar[i]>0)
len++;
else if(i%2==0&&ar[i]<0)
len++;
else
{
if(max<len)
max=len;
len=0;
j=i;
break;
}
}
}
}
return max;
}

int main(void)
{
int N;
int ar[MAX];
scanf("%d",&N);
printf("\n");
int i,l=0,j,k=0,count=0;
int len[N];
for(i=0;i<N;i++)
{
count=0;
for(j=0;j<10;j++)
{
scanf("%d",&ar[j]);
count++;
}
int r[count];
k=0;
for(j=0;j<(count-2);j++)
{
r[k++]=ar[j+1]-ar[j];
}
r[count-1]=0;
len[l++]=lonlen(r,count);
printf("\n");
}

for(i=0;i<N;i++)
printf("%d \n",len[i]);
return 0;
}
