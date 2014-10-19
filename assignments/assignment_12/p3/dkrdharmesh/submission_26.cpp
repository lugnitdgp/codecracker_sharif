#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    int t,n,ans,s,i;
    scanf("%d",&t);
    char a[105];
    while(t--)
    {
        ans=0;
        scanf("%s",&a);
        s=strlen(a);
        for(i=0;i<s;i++)
        if((a[i]=='D')||(a[i]=='J')||(a[i]=='0'))
        {
            ans=1;
        }
        if(ans==1)
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}
