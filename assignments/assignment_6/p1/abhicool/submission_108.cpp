#include<iostream.h>
#include<conio.h>
#include<string.h>
struct word
{
     char a[25];
};
 void main()
{
    int n,r;
    char *w,a[25];
    cout<<"enter no of cases";
    cin>>n;
     for(i=0;i<n;i++)
     { 
         
    cin>>l;
     cin>>a;
     cin>>r;
     sort(a,l);
    a[i]=rank(a,r,l);
         
     }

sort(char *a[],int l)
{  int i,j;
  char *t;
    for(i=0;i<l-1;i++)
    {
        for(j=i+1;j<l;j++)
        {
             *t=*a[i];
             *a[i]=*a[j];
             *a[j]=*t;
             
        }
    }
    
    
}
rank(char a[],int r2,int l1)
{
    
    int r3=r2;
    rem=r3%l1;
    q=r3/l1;
    char b[25]=a;
    for(i=0;i<q-1;i++)
    cout<<a[0];
    cout<<a[rem];
    for(i=q;i<l1;i++)
    {
        cout<<a[i];
        }
    
    
}
    
}
{
    
    
    
}