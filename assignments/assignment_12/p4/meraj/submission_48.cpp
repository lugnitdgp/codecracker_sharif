#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

long long int m, n;

long long int ct(long long int **arr, long long int p, long long int q, long long int val)
{
    if(p<0 || p>=m || q<0 || q>=n)
    {
        return 0;
    }
    if (arr[p][q]!=val)
    {
        return 0;
    }
    else
    {
        arr[p][q]=-1;
    }
    if(p==0 && q==0)
    {
        return (1+ct(arr, p+1, q, val)+ct(arr, p, q+1, val));
    }
    else if(p==m && q==0)
    {
        return (1+ct(arr, p-1, q, val)+ct(arr, p, q+1, val));
    }
    else if(p==m && q==n)
    {
        return (1+ct(arr, p-1, q, val)+ct(arr, p, q-1, val));
    }
    else if(p==0 && q==n)
    {
        return (1+ct(arr, p+1, q, val)+ct(arr, p, q-1, val));
    }
    else if(p==0)
    {
        return (1+ct(arr, p+1, q, val)+ct(arr, p, q-1, val)+ct(arr, p, q+1, val));
    }
    else if(p==m)
    {
        return (1+ct(arr, p-1, q, val)+ct(arr, p, q-1, val)+ct(arr, p, q+1, val));
    }
    else if(q==0)
    {
        return (1+ct(arr, p, q+1, val)+ct(arr, p-1, q, val)+ct(arr, p+1, q, val));
    }
    else if(q==n)
    {
        return (1+ct(arr, p, q-1, val)+ct(arr, p+1, q, val)+ct(arr, p-1, q, val));
    }
    else
    {
        return (1+ct(arr, p+1, q, val)+ct(arr, p, q+1, val)+ct(arr, p-1, q, val)+ct(arr, p, q-1, val));
    }
}

int main()
{
    long long int ans, i, j, t, **arr, hash[10]={0}, ha[10]={0}, tem, max=0;
    char str[300];
    cin>>t;
    while (t--)
    {
        cin>>m>>n;
        arr=new long long int *[m];
        for (i=0; i<m; i++)
        {
            arr[i]=new long long int[n];
        }
        for (i=0; i<m; i++)
        {
            cin>>str;
            for (j=0; j<n; j++)
            {
                arr[i][j]=str[j]-48;
            }
        }
        for (i=0; i<m; i++)
        {
            for (j=0; j<n; j++)
            {
                if (arr[i][j]==-1)
                {
                    continue;
                }
                else
                {
                    tem=arr[i][j];
                    ans=ct(arr, i, j, arr[i][j]);
                    //cout<<"Jerry can collect "<<ans<<" candy of Delish value "<<tem<<endl;
                    if (hash[tem]==ans)
                    {
                        ha[tem]++;
                    }
                    else if(ans>hash[tem])
                    {
                        ha[tem]=1;
                        hash[tem]=ans;
                    }
                }
            }
        }
        j=0;
        max=hash[0];
        for (i=1; i<10; i++)
        {
            if (hash[i]>=max)
            {
                max=hash[i];
                j=i;
            }
        }
        cout<<hash[j]<<" "<<j<<" "<<ha[j]<<endl;
        max=0;
        for (i=1; i<10; i++)
        {
            hash[i]=0;
            ha[i]=0;
        }
        delete [] arr;
    }
    return 0;
}
