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

char arr[26],temp[MAX5];

int merge(char *a,int size,int counter)
{
	int i=0,k=0,j=size;
	while(i<size && j<counter)
	{
		if(a[i]<=a[j])
		{
			temp[k]=*(a+i);
			i++;
		}
		else
		{
			temp[k]=*(a+j);
			j++;
		}
		k++;
	}
	while(i<size)
	{
		temp[k]=*(a+i);
		i++;
		k++;
	}
	while(j<counter)
	{
		temp[k]=*(a+j);
		j++; k++;
	}
	for(i=0;i<counter;i++)
		a[i]=temp[i];
	return 0;
}


int main()
{
	int t,n,i,j,x,size;
	int a[MAX5];
	sin(t);
	while(t--)
	{
		sin(n);
		sst(arr);
		for(i=1;i<n;i=2*i)
	    {
	        for(j=0;j<n-i;j=j+2*i)
	        {
	            if((n-j)>2*i)
	                merge(&arr[j],i,2*i);
	            else
	                merge(&arr[j],i,(n-j));
	        }
	    }
	    sin(x);
	    j=0;
	    while(x>0)
	    {
	    	a[j]=(x-1)%n;
	    	x=(x-1)/n;
	    	j++;
	    }
	    j--;
	    while(j>=0)
	    {
	    	printf("%c",arr[a[j]]);
	    	j--;
	    }
	    printf("\n");
	}
	return 0;
}
