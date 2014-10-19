    #include<iostream>
    #include<stdio.h>
    #include<cmath>
    #include<algorithm>
    #define ll long long int
    #define sf(x) scanf("%d",&x)
    #define pf(x) printf("%d\n",x)
    
    using namespace std;
    
    
int main()
{
    int t,i,j,s;
    int a[21];
    cin>>t;
    while(t--)
    {
              cin>>a[0];
              for(i=1;i<=a[0];i++)
              cin>>a[i];
              sort(a+1,a+a[0]+1);
              i=2;
              j=a[0];
              if(a[0]==1)
              cout<<a[1];
              else{
                   s=a[i];
                   while(i<j)
                   {
                             s=s+a[1]+a[j];
                             j-=2;
                             if(i<=j)
                             {
                                     s=s+2*a[2];
                             }
                   }
                   cout<<s<<endl;
              }
              
    }
    return 0;
}
    
