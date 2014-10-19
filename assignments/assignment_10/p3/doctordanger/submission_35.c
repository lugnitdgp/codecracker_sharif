#include<stdio.h>
int main()
{
  int t;
  int a,b,c;
  float d1,d2,min;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d%d",&a,&b,&c);
    d1=b-a;
    d2=c-b;
    if(d1==d2)
      min=0;
    else
    {
      min=(d1+d2)/2;
      
      min=b-a-min;
      if(min<0)
	min=-min;
    }
    printf("%0.2f\n",min);
  }
  return 0;
}