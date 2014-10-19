#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX9 1000000007
#define MAX6 1000005
#define MAX5 100005

#define sin(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sst(x) scanf("%s",x)

#define pin(x) printf("%d",x)
#define pll(x) printf("%lld",x)
#define pst(x) printf("%s",x)
#define nl() printf("\n")
#define psp() printf(" ")

#define fon(x,n) for(x=0;x<n;x++)

int arr[MAX5];

int main()
{
	int t,n,i,j,len,flag,max;
	char c;
	sin(t);
	while(t--)
	{
		fon(i,MAX5)
		{
			sin(arr[i]);
			c=getchar();
			if(c=='\n')
				break;
		}
		n=i+1;
		if(n==1)
			printf("1\n");
		else
		{
			len=1;
			i=1;
			while(arr[i]==arr[i-1] && i<n)
				i++;
				
			if(i==n)
				printf("0\n");
			else
			{
				len=max=2;
				if(arr[i]>arr[i-1])
					c='+';
				else
					c='-';
				i++;
				while(i<n)
				{
					if(len!=0)
					{
						if(c=='-' && arr[i]>arr[i-1])
						{
							len++;
							c='+';
						}
						else if(c=='+' && arr[i]<arr[i-1])
						{
							len++;
							c='-';
						}
					}
					else if(arr[i]!=arr[i-1])
					{
						len=2;
						if(arr[i]>arr[i-1])
							c='+';
						else
							c='-';
						i++;
					}
					else
						len=0;
					
					if(max<len)
						max=len;
					i++;
				}
				pin(max);
				nl();
			}
		}
	}
	return 0;
}
