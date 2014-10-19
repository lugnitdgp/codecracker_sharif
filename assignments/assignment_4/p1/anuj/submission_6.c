#include <stdio.h>
#include <stdlib.h>
int main() {
	int i, j, n, t;
	/*printf("10\n");
	for(i=0; i<10; i++) {
		n = rand()%999999;
		printf("%d\n", n);
		for(j=0; j<n; j++) {
			printf("%d ", rand()%20000000);
		}
		printf("\n");
	}
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", a+i);
		}
		for(i=0; i<n; i++) {
			printf("%d ", *(a+i));
		}
		printf("\n");
	}*/
	int a[] = {3, 26, 35,	8,	36,	9,	26,	2,	17,	6,	37,	2,	1,	5,	7,	1,	1,	6,	3,	2,	1,	3};
	for(i=0; i<22; i++) printf("%d\n", a[i]);
	return 0;
}