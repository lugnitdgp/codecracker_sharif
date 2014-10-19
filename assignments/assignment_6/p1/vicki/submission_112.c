// problem 1 of NIT durgapur's Mukti-2014 round 1

# include <stdio.h>
char s[100000]; char w[27];

void sort(long long n)
{
	int i, j; char temp;
	for(i = 0; i<n; i++)
	{
		for(j=i; j<n; j++)
		{
			if(w[j] < w[i])
			{
				temp = w[i];
				w[i] = w[j];
				w[j] = temp;
			}
		}
	} return;
	
	temp = w[0];
	w[0] = w[n-1];
	for (i = n-2; i>0; --i)
	{
		w[i+1] = w[i];
	}	
	w[1] = temp;
	
	w[n+1] = '\0';
}

long long power(long long a, long long b)
{
	long long i = 1;
	while(b--)
		i = a*i;
	return i;
}

long long find_len(long long n, long long r)
{
	long long len = 1; long long m = n;
	while(r > n)
	{
		r = r-n;
		n = n*m;
		len++;
	}
	return len;
}


int main()
{
	int t; long long n, r, i, j, k, len;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld", &n);
		scanf("%s", w);
		scanf("%lld",&r);
		sort(n);
		//printf("%s\n", w); //return 0;
		len = find_len(n, r);
		//printf("%lld\n", len);
		/*
		for(i=0; i<len; i++)
		{
			s[len-1-i] = w[r%n];
			r= r/n;
		}
		*/
		
		
		for(i = 1; i<len; i++)
			r = r - power(n, i);
		r--;
		j = power(n, len-1);
		for(i=0; i<n; i++)
		{
			printf("%c", w[r/j]);
			j = j/n;
		}
		printf("\n");


	}
}

