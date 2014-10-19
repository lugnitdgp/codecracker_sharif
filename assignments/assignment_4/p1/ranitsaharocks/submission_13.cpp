#include<iostream>

using namespace std;
int main()
{
int a,b,c,d;
cout<<"Enter test cases :: ";
cin>>a;
for(b=1;b<=a;b++)
{
cout<<"Enter the elements of sequence<<b<< :: ";
for(c=0;c<a;c++)
cin>>d[c];
}
for(b=1;b<=a;b++)
{
for(c=0;c<a;c++)
{
if(d[c+1]>d[c] && d[c+2]<d[c+1])
cout<<"d[c+2]"<<"\n";
}
}


return 0;
}