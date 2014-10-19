#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	long long int i,t,m1,c,j,k,l,m,T,n,d;
	char *a,x,**b;
	scanf("%lld",&T);
	t=T;
	b=(char**)malloc(T*sizeof(char*));
	while(T--)
	{
		scanf("%lld",&m);
	
		a=(char*)malloc((m+1)*sizeof(char));
		scanf("%s",a);	
		scanf("%lld",&n);
		
    for(i=0;a[i]!='\0';i++)	
	{
		for(j=i;a[j]!='\0';j++)
		{
			l=a[i];
			k=a[j];
			if(l>k)
			{
			x=a[i];
			a[i]=a[j];
			a[j]=x;
				
			}
		}
	}	
	c=0;
	m1=m;
	while(n/m1!=0)
	{
		n=n-m1;
		m1=m1*m1;
		c++;
	
		
		
	}
	d=n%m1;
	//printf("%lld %lld\n ",n,m1);
	if(d>0)
	c++;
	k=0;
	*(b+T)=(char*)malloc(c+1*sizeof(char));
	
	l=1;
	for(j=1;j<=c-1;j++)
	{
		l*=m;
	}
	//printf("%lld %lld %lld l",l,m,c-1);
	
	for(j=0;j<c;j++)
	{
	i=d/l;
 	if(d%l==0)
	i--;
	//printf("%lld %lld %lld",i,d,l);
	b[T][k]=a[i];
	k++;
	d=d-l*i;
	l=l/m;
    }
    b[T][k]='\0';
    //printf("%s\n",b);
    
	
	
	
	}
	for(i=t-1;i>=0;i--)
	{
		printf("%s\n\n",*(b+i));
	}
	return 0;
}