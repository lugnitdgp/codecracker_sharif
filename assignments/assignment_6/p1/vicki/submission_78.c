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
	}
temp = w[0];
				w[0] = w[n];
				w[n] = temp;	w[n+1] = '\0';
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

find_word(long long n, long long len)
{
	long long i;

}

int main()
{
	int t; long long n, r, i, j, k, len;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld", &n);
		scanf("%s", w);
		sort(n);
		printf("%s\n", w);
		l = find_len(n, r);
		for(i = 1; i<len; i++)
			r = r - power(n, i);
		j = power(n, len-1)
		for(i=0; i<n; i++)
		{
			printf("%c", w[r%j]);
			j = j/n;
		}
	}
}

