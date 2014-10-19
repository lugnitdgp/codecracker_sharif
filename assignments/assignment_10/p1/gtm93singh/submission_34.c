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
	int x,y,v;
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
		flag=sum1=sum2=f2=0;
		fon(i,n)
		{
			sin(arr[i].x);sin(arr[i].y);sin(arr[i].v);
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
	    temp=0;
		fon(i,n)
	    {
	    	if(i==0 || arr[i].x!=nbr)
	    	{
	    		if(temp>sum1)
	    		{
	    			sum1=temp;
	    			x=nbr;
	    			flag=0;
	    		}
	    		else if(temp==sum1)
	    			flag=1;
	    		
				temp=arr[i].v;
	    		nbr=arr[i].x;
	    	}
	    	else
	    	{
	    		temp+=arr[i].v;
	    	}
	    }
	    
	    if(temp>sum1)
		{
			sum1=temp;
			flag=0;
			x=nbr;
		}
		else if(temp==sum1)
			flag=1;
	    
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
	    temp=0;
	    fon(i,n)
	    {
	    	if(i==0 || arr[i].y!=nbr)
	    	{
	    		if(temp>sum2)
	    		{
	    			sum2=temp;
	    			f2=0;
	    			y=nbr;
	    		}
	    		else if(temp==sum2)
	    			f2=1;
	    		
				temp=arr[i].v;
	    		nbr=arr[i].y;
	    	}
	    	else
	    	{
	    		temp+=arr[i].v;
	    	}
	    }
	    if(temp>sum2)
		{
			sum2=temp;
			f2=0;
			y=nbr;
		}
		else if(temp==sum2)
			f2=1;
	    	    
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
