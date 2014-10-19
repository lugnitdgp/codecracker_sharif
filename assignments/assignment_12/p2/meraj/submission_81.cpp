#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
    long long int ct1, ct2, t, sq, i, n, *arr;
    cin>>t;
    while (t--)
    {
        cin>>n;
        arr=new long long int[n];
        for (i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        ct1=ct2=0;
        for (i=0; i<n; i++)
        {
            while (arr[i]>4)
            {
                sq=sqrt(arr[i]);
                ct1++;
                arr[i]-=pow(sq,2);
            }
            ct2+=arr[i];
        }
        if (ct1%2==0)
        {
            if (ct2%2==0)
            {
                cout<<"Durga\n";
            }
            else
                cout<<"Aayush\n";
        }
        else
        {
            if (ct2%2!=0)
            {
                cout<<"Durga\n";
            }
            else
                cout<<"Aayush\n";
        }
        delete [] arr;
    }
    return 0;
}