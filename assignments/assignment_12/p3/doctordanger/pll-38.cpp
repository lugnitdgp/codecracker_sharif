#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t;
    string s;
    cin>>t;
    int flag;
    while(t--)
    {
        flag=0;
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='D'||s[i]=='J'||s[i]=='0')
            {
                  flag=1;
                  break;
            }
        }
        if(flag==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
