//write your code here
#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test>0)
		{
			long n,k;
			long a,b,count=0;
			cin>>n>>k;
			for(a=n;a<=k;a++)
				for(b=a;b<=k;b++)
				{
				 if((a-n)*(b-n)==0)
				 continue;
 
				 if(((a*b)-n)%((a-n)*(b-n))==0)
				 count++;
				}
			cout<<"\n"<<count<<"\n";	
			test--;
		}
	return 0;
}