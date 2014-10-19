/*
  Name: Santhosh Reddy
  Problem: 
  Algo..etc: 
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#define ss(a) scanf("%s",a)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define pi(a) printf("%d ",a)
#define pl(a) printf("%ld ",a)
#define ps(a) printf("%s ",a)
#define For(i,n) for(i=0;i<n;i++)
#define fOR(i,n) for(i=1;i<=n;i++)
#define nl printf("\n")
#define MAX 
//set<int> sx, sy;
using namespace std;

int main(){
	char s[100];
	int n;
	si(n);
	while(n--){
		scanf("%s",s);
		int l=0,cnt=0;
		l=strlen(s);
		if(l<5)printf("-1\n");
		else {
			if(!(s[0]=='L'||s[0]=='l'))cnt++;
			if(!(s[1]=='I'||s[1]=='i'))cnt++;
			if(!(s[l-1]=='X'||s[l-1]=='x'))cnt++;
			if(!(s[l-2]=='U'||s[l-2]=='u'))cnt++;
			for(int i=2;i<=l-3;i++){
				if(!(s[i]=='n'||s[i]=='N'))cnt++;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}


