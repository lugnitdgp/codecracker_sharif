#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    char s[200];
    int T,f=0;cin>>T;
    while(T--)
    {
        f=0;
        scanf("%s",s);
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='D'||s[i]=='J'||s[i]=='0'||s[i]=='+')
            {
                cout<<"YES"<<endl;f=1;break;
            }
        }
        if(f!=1)cout<<"NO"<<endl;
    }
}