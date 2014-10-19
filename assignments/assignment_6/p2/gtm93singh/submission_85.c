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

int arr[20][20],n,mark[20],flag;

int dfs(int node, int count)
{
	int i;
	if(node==n-1)
		flag=1;
	fon(i,n)
	{
		if(arr[node][i]==1 && node!=i) 
		{
			if(i==0)
			{
				if(flag==1)
					return count;
				else
					return -1;
			}
			else if(mark[i]==0)
			{
				count=dfs(i,count+1);
				if(count!=-1 && flag==1)
					break;
			}
		}
	}
	if(i==n)
		return -1;
	else
		return count;
}

int main()
{
	int t,i,x,j,count;
	sin(t);
	while(t--)
	{
		sin(n);
		fon(i,n)
		{
			sin(x);
			arr[x][i]=1;
			mark[i]=0;
		}
		mark[0]=1;
		count=-1;
		fon(i,n)
		{
			if(mark[i]!=1 && arr[0][i]==1 && i!=0)
			{
				flag=0;
				mark[i]=1;
				count=dfs(i,1);
				if(count!=-1 && flag==1)
					break;
				mark[i]=0;
			}
		}
		if(count==-1 || i==n)
			printf("HORRIBLE");
		else
		{
			count=2*count-1;
			pin(count);
		}
		nl();
		fon(i,20)
		{
			fon(j,20)
				arr[i][j]=0;
			mark[i]=0;
		}
	}
	return 0;
}
