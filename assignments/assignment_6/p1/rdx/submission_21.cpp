    #include<iostream>
    #include<stdio.h>
    #include<cmath>
    #define ll long long int
    #define sf(x) scanf("%d",&x)
    #define pf(x) printf("%d\n",x)
    
    using namespace std;
    
    
int main()
{
    ll t,l,x,r;
    int i,j,m;
    char ar[26],b[100000];
    cin>>t;
    while(t--)
    {
              cin>>l>>ar>>r;
              for(i=1;i<l;i++)
              {
                     for(j=0;j<l-i;j++)
                     {
                                       if(*(ar+j)>*(ar+j+1))
                                       {
                                                         *(ar+j)=*(ar+j)+*(ar+j+1);
                                                         *(ar+j+1)=*(ar+j)-*(ar+j+1);
                                                         *(ar+j)=*(ar+j)-*(ar+j+1);
                                       }
                     }
              }
              x=0;
              while(r>0)
              {
                        m=r%l;
                        if(m>0)
                        m--;
                        b[x]=ar[m];
                        x++;
                        r=r/l;
              }
              x--;
              while(x>=0)
              cout<<b[x--];
              cout<<endl;
    }
    return 0;
}
