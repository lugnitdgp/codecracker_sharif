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

struct node
{
	int down,right,pet;
}arr[25][25];

int cost[25][25];

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main()
{
	int t,n,i,j,k,temp;
	sin(t);
	while(t--)
	{
		sin(n);
		fon(i,n+1)
		{
			fon(j,n+1)
			{
				if(i*j==0)
					arr[i][j].down=arr[i][j].right=cost[i][j]=arr[i][j].pet=0;
				else
					sin(arr[i][j].pet);
			}
		}
		temp=2*n-1;
		for(i=1;i<=temp;i++)
		{
			j=1;
			if(i%2)
			{
				while(j<n)
				{
					sin(arr[(i+1)/2][j].right); j++;
				}
			}
			else
			{
				while(j<=n)
				{
					sin(arr[i/2][j].down); j++;
				}
			}
		}
		k=1;
		while(k<=n)
		{
			for(i=k;i<=n;i++)
			{
				for(j=k;j<=n;j++)
				{
					if(arr[i][j].pet==-1)
						cost[i][j]=-1;
					else if(cost[i][j-1]<0 && cost[i-1][j]<0)
						cost[i][j]=-1;
					else if(cost[i-1][j]-arr[i-1][j].down<0 && cost[i][j-1]-arr[i][j-1].right<0)
						cost[i][j]=-1;
					else if(cost[i][j-1]<0)
					{
						if(cost[i-1][j]-arr[i-1][j].down<0)
							cost[i][j]=-1;
						else
							cost[i][j]=cost[i-1][j]-arr[i-1][j].down+arr[i][j].pet;
					}
					else if(cost[i-1][j]<0)
					{
						if(cost[i][j-1]-arr[i][j-1].right<0)
							cost[i][j]=-1;
						else
							cost[i][j]=cost[i][j-1]-arr[i][j-1].right+arr[i][j].pet;
					}
					else
					{
						temp=max((cost[i][j-1]-arr[i][j-1].right),(cost[i-1][j]-arr[i-1][j].down));
						cost[i][j]=temp+arr[i][j].pet;
					}
				}
			}
			k++;
		}
		if(cost[n][n]<=0)
			printf("MURDER");
		else
			pin(cost[n][n]);
		nl();
		fon(i,n+1)
		{
			fon(j,n+1)
			{
				arr[i][j].pet=arr[i][j].down=arr[i][j].right=0;
				cost[i][j]=0;
			}
		}
	}
	
	return 0;
}

