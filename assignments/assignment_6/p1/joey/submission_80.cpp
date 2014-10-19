//write your code here
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<fstream>
using namespace std;
unsigned long long power(unsigned long long a,unsigned long long n)
{
 unsigned long long res=1;
 while(n>0)
 {
  if(n&1) res=(res*a);
  a=(a*a);
  n/=2;         
 } 
 return res;     
}
int main()
{
 unsigned long long u,i,j,k,t,l,n;char s[30];
 //freopen("labelmaker.txt","r",stdin);
 //freopen("a.txt","w",stdout);
 cin>>t;
 for(k=1;k<=t;k++)
 {
  cin>>u;
  cin>>s>>n;
  char *res=new char[60];          
  l=strlen(s);
  sort(s,s+l);
  unsigned long long sub,sum=0,num,ni;
  for(i=0;i<=50;i++)
  {
   sum+=power(l,i);
   if(sum>n) {sum-=power(l,i);i--;break;}                 
  }      
  n-=sum;
  num=i;i=0;
  for(j=num;j>=1;j--)
  {
   ni=n/power(l,j);
   sub=(ni*power(l,j));
   n=n-sub;
   res[i++]=s[ni];        
  }   
  res[i++]=s[n];
  res[i]='\0';
  printf("%s\n",res);
  delete res;
 }   
 return 0;    
}
