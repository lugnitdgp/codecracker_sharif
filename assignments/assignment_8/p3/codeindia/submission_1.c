//write your code here
#include <stdio.h>
#define MAX 10001
int phi[MAX] ;
void calc(){
int i,j;
for (i=2;i<MAX;phi[i]=i++) ;
for (i=2;i<MAX;i++)
if (phi[i]==i)
for(j=i;j<MAX;phi[j]-=phi[j]/i,j+=i);
}
int main(){
calc() ;
int t,n;
scanf("%d",&t) ;
while(t--){
scanf("%d",&n) ;
printf("%d\n",phi[n]) ;
}
return 0 ;
}