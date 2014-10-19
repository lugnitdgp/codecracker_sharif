#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        float ans,a1,c1;
        a1=a;c1=c;
        ans=((a1+c1)/2)-b;
        if(ans>=0)
            printf("%.2f\n",(ans));
        else    printf("%.2f\n",-ans);
    }
    return 0;

}
