#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int times;
    int n;
    int a[100];
    int i;
    scanf("%d", &times);
    while (times--)
    {
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            scanf("%d", &a[i]);
       // for (i = 1; i <= n; i++)
          //  printf("%d", a[4]);    
        sort(a, a+n+1);
        int sum = 0;
        //i = 0;
        int k;
        if (0 == 0)
        {
            for (k = 2; k <=n; k=k+2){
                sum += a[k];//printf("i%d %di ", k, a[k]);
                k += 2;
            }
           // printf("s = %d ", sum);  
            for (i = 1; i <= n/2; i++)
            {
                sum += a[i];
            }
            //printf("%d ", sum);  
            for (i = 1; i <= n/2; i += 1)
            {
                sum += a[i];
            }
            //printf("%d ", sum);  
        }
         if (n%2 != 0) sum+= a[(n+1)/2];   
     printf("%d\n", sum);   
    }
    return 0;
}
    
    