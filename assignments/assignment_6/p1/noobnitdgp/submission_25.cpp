#include <cstdio>
#include <iostream>
#include <math.h>
#include <stdlib.h>

long long int temp=0, temp1=0;
long long int flag=0;

using namespace std;


long long int gen(char *str, char *ans, long long int i, long long int len, long long int n);
long long int gen(char *str, char *ans, long long int i, long long int len, long long int n)
{
    if (i==len)
    {
        temp--;
        if (temp==0)
        {
            cout<<ans<<"\n";
            flag=1;
        }
        return 0;
    }
    long long int it=0;
    for (it=0; it<n; it++)
    {
        ans[i]=str[it];
        gen(str, ans, i+1, len, n);
        if (flag==1)
        {
            return 0;
        }
    }
    return 0;
}


int main()
{
    long long int i=1, t, n, r, j, k;
    char *str, *ans, l;
    cin>>t;
    while (t!=0)
    {
        t--;
        cin>>n;
        str=new char[n];
        cin>>str;
        cin>>r;
        while (temp1<r)
        {
            temp=temp1;
            temp1+=pow(n, i);
            i++;
        }
        i--;
        temp=r-temp;
        for (j=0; j<n; j++)
        {
            for (k=j+1; k<n; k++)
            {
                if (str[j]>str[k])
                {
                    l=str[j];
                    str[j]=str[k];
                    str[k]=l;
                }
            }
        }
        ans=new char[i];
        cout<<str<<endl;
        gen(str, ans, 0, i, n);
        flag=0;
        temp=0;
        temp1=0;
        i=1;
        delete [] str;
        delete [] ans;
    }
    return 0;
}