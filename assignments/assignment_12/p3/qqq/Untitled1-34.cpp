#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int t,len,i;
	char arr[150];
	cin>>t;
	while(t--)
	{
		cin>>arr;
		len=strlen(arr);
		for(i=0;i<len;i++)
		{
			if(arr[i]=='D'||arr[i]=='J'||arr[i]=='0')
			{
				cout<<"YES"<<endl;
				break;
			}
		}
		if(i==len)
			cout<<"NO"<<endl;
	}
	return 0;
}
