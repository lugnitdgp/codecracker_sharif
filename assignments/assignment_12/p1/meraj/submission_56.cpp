#include <cstdio>
#include <iostream>

using namespace std;

/*long long int p(long long int x)
{
    if (x==0)
    {
        return 1;
    }
    else
    {
        return (2*(p(x-1)00000007));
    }
}*/

int main()
{
    long long int i, t, n, k, t1=1;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        t1=1;
        //t1=p(n-1);
        for (i=1; i<n; i++)
        {
            t1*=2;
            t1%=1000000007;
        }
        if (k>=n)
        {
            cout<<t1<<endl;
        }
        else
        {
            cout<<(t1-(n-k))<<endl;
        }
    }
    return 0;
}