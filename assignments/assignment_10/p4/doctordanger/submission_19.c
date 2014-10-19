#include<stdio.h>
int getmax(int a[],int v,int l,int n)
{
  //printf("fn");
  if(n>=l)
  {
  if(n==l)
  {
    if(v==a[l])
    return 1;
    else
      return 0;
  }
  else
  {
    int mid=(l+n)/2;
    int left=getmax(a,v,l,mid);
    int right=getmax(a,v,mid+1,n);
    return left+right;
  }
  }
  return 0;
}
int main()
{
  int t,n,m,i;
  int a[100000];
  int v,l,r;
  int output;
  scanf("%d",&t);
  while(t--)
  {
      scanf("%d%d",&n,&m);
      for(i=0;i<n;i++)
	scanf("%d",&a[i]);
      for(i=0;i<m;i++)
      {
	scanf("%d%d%d",&v,&l,&r);
	output=getmax(a,v,l-1,r-1);
	if(output==0)
	  printf("No 0\n");
	else
	  printf("Yes %d\n",output);
      }
  }
  return 0;
}