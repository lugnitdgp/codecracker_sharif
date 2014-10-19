#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    bool flag=false;
    int t, i, len;
    char str[500];
    cin>>t;
    while (t--)
    {
        cin>>str;
        len=strlen(str);
        for (i=0; i<len; i++)
        {
            if (str[i]=='D' || str[i]=='J' || str[i]=='+' || str[i]=='0')
            {
                flag=true;
                break;
            }
        }
        if (flag)
        {
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
        flag=false;
    }
    return 0;
}