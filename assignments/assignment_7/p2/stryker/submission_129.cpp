#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int times;
	scanf("%d", &times);
	while (times--)
	{
		int a[15];
		int n;
		int i;
		int sum = 0;
		scanf("%d", &n);
		
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if (n%2==0) {
		for (i = 2; i <= n; i=i+2)
		{
			sum += a[i];
		}
		
		for (i = 1; i <= n/2; i++)
			sum += a[i];
		
		for (i = 1; i <= n/2; i=i+2)
			sum += a[i];
		
		if (n % 2 == 1) sum += a[(n+1)/2];
		printf("%d\n", sum);
	}
	else {
		for (i = 2; i <= n/2; i=i+2)
		{
			sum += a[i];
		}
		for (i = n/2+3; i <= n; i=i+2)
		{
			sum += a[i];
		}
		for (i = 1; i <= n/2; i++) sum += (2*a[i]);
		sum += a[(n+1)/2];
		printf("%d\n", sum);
	}
	}
	return 0;
}