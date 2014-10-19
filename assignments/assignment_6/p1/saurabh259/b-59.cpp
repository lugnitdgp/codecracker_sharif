#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main(){
	int i,j,mod,t,cas=1;
	unsigned long long int n,div;
	int ans[100];
	char str[27];
	
	scanf("%d",&t);
	while(t--)
	{
			i=0;
			int len;
			scanf("%d %s %llu",&len,str,&n);
			sort(str,str+len);
			while(n>0){
				mod=n%len;
				div=n/len;
				if(mod==0)
				{
					mod=len;
					n=div-1;
				}
				else
				n=div;
				
				ans[i]=mod;
				i++;
			}
			
			for(j=i-1;j>=0;j--){
				printf("%c",str[ans[j]-1]);
			}
			printf("\n");
			cas++;
	}
	return 0;
}
