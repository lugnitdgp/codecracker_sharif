#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{

    int f=0;char s[150];
    int T;
    cin>>T;
    while(T--)
    {
    	f=0;
    	scanf("%s",s);
	    for(int i=0;i<strlen(s);i++)
	    {
	        if(s[i]=='D'||s[i]=='J'||s[i]=='0')
	        {
	            cout<<"YES"<<endl;f=1;
	            break;
	        }
	    }
	    if(f!=1)
	        cout<<"NO"<<endl;
	}
}
