#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int t;
  int n;
  long a[100000];
  long b[100000];
  cin>>t;
  int d,i,min,p,q;
  while(t--)
  {
    min=1000000;
    cin>>n;
    for(i=0;i<n;i++)
    { cin>>a[i];b[i]=i;}
    sort(a,a+n-1);
   // for(i=0;i<n;i++)
     // cout<<a[i]<<" ";
    for(i=0;i<n-1;i++)
    {
      d=a[i+1]-a[i];
      if(d<0)
	d=-d;
      if(d<min)
      {min=d;}
    }
    cout<<min<<endl;
  }
}