#include <cstdio>
#include <iostream>

using namespace std;

int po(int x)
{
    if (x==0)
    {
        return 1;
    }
    else
    {
        return (2*(po(x-1)00000007));
    }
}

int main()
{
    int t, n, k, t1;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        t1=po(n-1);
        if (k>n)
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