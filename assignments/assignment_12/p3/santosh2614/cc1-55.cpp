#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long int lli;
inline int scan()
{
int t=0;
char c;
c=getchar();
while(c<'0' || c>'9')
c=getchar();
while(c>='0' && c<='9')
{
t=(t<<3)+(t<<1)+c-'0';
c=getchar();
}
return(t);
}
int main()
{ char s[101];
 int t,i,j,k;
 t = scan();
 while(t>0)
 {cin>>s;
 int l = strlen(s);
 for(i=0;i<l;i++)
 {if(s[i]=='D'||s[i]=='0'||s[i]=='J')
 {printf("YES\n");
 break;


 }


 }

 t--;}



}
