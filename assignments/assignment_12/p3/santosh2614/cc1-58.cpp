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
 int st, t,i,j,k;
 t = scan();
  st =0;
 while(t>0)
 {cin>>s;
 int l = strlen(s);
 for(i=0;i<l;i++)
 {if(s[i]=='D'||s[i]=='0'||s[i]=='J')
 {printf("YES\n");
st=1;
 break;


 }


 }

 if(st==0)
 {
     printf("NO\n");

 }

 t--;}



}
