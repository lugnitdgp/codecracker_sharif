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
	long long int x,y,v;
};
typedef struct node nd;

nd arr[100005],temp[100005];

int merge1(nd *a,int size,int counter)
{
	int i=0,k=0,j=size;
	while(i<size && j<counter)
	{
		if(a[i].x<=a[j].x)
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

int merge2(nd *a,int size,int counter)
{
	int i=0,k=0,j=size;
	while(i<size && j<counter)
	{
		if(a[i].y<=a[j].y)
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
	int t,m,n,i,j,x,y,flag,f2;
	long long int sum1,sum2,nbr,temp;
	
	sin(t);
	while(t--)
	{
		sin(m);
		sin(n);
		fon(i,n)
		{
			sll(arr[i].x); sll(arr[i].y); sll(arr[i].v);
		}
		
		for(i=1;i<n;i=2*i)
	    {
	        for(j=0;j<n-i;j=j+2*i)
	        {
	            if((n-j)>2*i)
	                merge1(&arr[j],i,2*i);
	            else
	                merge1(&arr[j],i,(n-j));
	        }
	    }
	    
		nbr=arr[0].x;
	    sum1=temp=arr[0].v;
	    x=arr[0].x;
		flag=0;
		for(i=1;i<n;i++)
	    {
	    	if(arr[i].x!=nbr)
	    	{	
				temp=arr[i].v;
	    		nbr=arr[i].x;
	    	}
	    	else
	    	{
	    		temp+=arr[i].v;
	    		if(temp>sum1)
	    		{
	    			sum1=temp;
	    			x=nbr;
	    			flag=0;
	    		}
	    		else if(temp==sum1)
	    			flag=1;
	    	}
		}
		
		for(i=1;i<n;i=2*i)
	    {
	        for(j=0;j<n-i;j=j+2*i)
	        {
	            if((n-j)>2*i)
	                merge2(&arr[j],i,2*i);
	            else
	                merge2(&arr[j],i,(n-j));
	        }
	    }
	    
	    nbr=arr[0].y;
	    sum2=temp=arr[0].v;
	    y=arr[0].y;
		f2=0;
		for(i=1;i<n;i++)
	    {
	    	if(arr[i].y!=nbr)
	    	{	
				temp=arr[i].v;
	    		nbr=arr[i].y;
	    	}
	    	else
	    	{
	    		temp+=arr[i].v;
	    		if(temp>sum2)
	    		{
	    			sum2=temp;
	    			y=nbr;
	    			f2=0;
	    		}
	    		else if(temp==sum2)
	    			f2=1;
	    	}
	    }
	    if(sum1>sum2)
	    {
	    	if(flag==1)
	    		printf("Bad Luck\n");
	    	else
	    	{
	    		printf("Row %d\n",x);
	    	}
	    }
	    else if(sum1==sum2)
	    {
	    	printf("Bad Luck\n");
	    }
	    else
	    {
	    	if(f2==1)
	    		printf("Bad Luck\n");
	    	else
	    	{
	    		printf("Column %d\n",y);
	    	}
	    }
	}
	return 0;
}
