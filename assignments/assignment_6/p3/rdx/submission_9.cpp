//write your code here
    #include<iostream>
    #include<stdio.h>
    #include<cmath>
    #define ll long long int
    #define sf(x) scanf("%lld",&x)
    #define pf(x) printf("%lld\n",x)
    
    using namespace std;
    
    
int main()
{
    ll t,n,k,p,s,x=0,y=1;
    sf(t);
    while(t--)
    {
              sf(n);
              sf(k);
              p=((n+2*(k-1))-(3*k))00000007;
              if(p==1 || k==1)
              pf(y);
              else
              {
                  if(p<0)
                  pf(x);
                  else
                  {
                      s=((p+1)/2+1)00000007;
                      pf(s);
                  }
              }
    }
    return 0;
}
