#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void printing(long long int num,int length,char * str,int q)
{
    char * arr = new char[length+1];
    int l = length;
    long long int z = num-1;
    length--;
    while(z!=0)
    {
        long long int v = z%q;
        arr[length--]=str[v];
        z = z/q;
    }
    while(length!=-1)
        arr[length--]=str[0];
    for(int i=0;i<l;i++)
        cout<<arr[i];
}

int main()
{
    int t;
    cin>>t;
    char str[20];
    while(t--)
    {
        long long int n,l;
        cin>>l;
        cin>>str;
        cin>>n;
        sort(str,str+l);
        long long int power = l;
        long long int count =1;
        while(n-power>0)
        {
            n=n-power;
            power=power*l;
            count++;
        }
        printing(n,count,str,l);
        cout<<endl;
    }
    return 0;
}

