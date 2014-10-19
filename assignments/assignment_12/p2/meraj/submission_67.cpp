#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long int t, n, x, sum=0;
    cin>>t;
    while (t--)
    {
        cin>>n;
        sum=0;
        while (n--)
        {
            cin>>x;
            sum+=x;
        }
        if (sum%2==0)
        {
            cout<<"Durga\n";
        }
        else
            cout<<"Aayush\n";
    }
    return 0;
}