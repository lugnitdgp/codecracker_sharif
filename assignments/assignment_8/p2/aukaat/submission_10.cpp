#include<iostream>
 
 
using namespace std;
 
int main()
{
  char a[100];
  cin>>a;
  int i=0,c,z=0;
  while(a[i]!='\0')
  	{
  		c=0;
  		if(a[i+2]=='a'||a[i+2]=='e'||a[i+2]=='i'||a[i+2]=='o'||a[i+2]=='u')
  			{
  			 c++;z++;}
  		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
  			{c++;z++;}
		if(a[i+1]=='a'||a[i+1]=='e'||a[i+1]=='i'||a[i+1]=='o'||a[i+1]=='u') 			
			{c++;z++;}
 
		if(c==0||c==3)
			{
				cout<<"is not acceptable.";
				return 0;
			}
			i++;
  	}
  	if(z>0)
  	cout<<"is acceptable.";
  	else
  	cout<<"is not acceptable.";
  	return 0;
}