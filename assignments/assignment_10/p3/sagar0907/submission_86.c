#include<stdio.h>
int main()
{
    int q,w,a,b,c;
    float x;
    scanf("%d",&q);
    for(w=0;w<q;w++)
    {
        scanf("%d %d %d",&a,&b,&c);
        x=b-(a+c)/2.0;
        if(x<0)
        x*=-1;
        printf("%.2f\n",x);
    }
    return 0;
}
