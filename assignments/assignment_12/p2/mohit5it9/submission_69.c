#include<stdio.h>
int main()
{
int t,i,n;
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
long long int sum,a[n];
for(i=0;i<n;i++)
{scanf("%lld",&a[i]);sum+=a[i];}
if(n%2==0 && sum%2==0)
printf("Durga\n");
else printf("Durga\n");
}
return 0;
}