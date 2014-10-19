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
	int t;
	si(t);
	while(t--){
		int a[7]={0,0,0,0,0,0,0};	
		int x,max=0,i;
		for(i=0;i<5;i++){
			si(x);
			a[x]++;
		}
		for(i=1;i<=6;i++){
			if(a[i]*i>max)max=a[i]*i;
		}
		printf("%d\n",max);
	}
	return 0;
}


