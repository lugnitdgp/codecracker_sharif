#include <iostream>
#include <string.h>
#include <stdio.h>


using namespace std;


int maxi_find(int a[],int n)
{
  int i,max=0;

  for(i=1;i<n;i++)
  {
    if(a[i]>a[max])
      max=i;
  }
  return max;
}

int min(int a,int b)

{
  if(a<b)
    return a;
  else 
    return b;
}

 int main()
 {
 	int t,n,*a,temp,sm,i,max_index,sum=0,sum1=0,sum2=0,count,eq_no;

 	cin>>t;

 	while (t)
 	{

 		cin>>n;
    sum=0;
    sum1=0;
    sum2=0;
 		a=new int[n];
 		for(i=0;i<n;i++)
 			cin>>a[i];
    
    for(i=0;i<n;i++)
      sum=sum + a[i];
    //cout<<"/n......."<<sum;
    if(sum % n!=0)
      cout<<"ANGRY";
    else
    {
      eq_no=sum/n;

    //cout<<"/n...eq_no...."<<eq_no;
      max_index=maxi_find(a,n);

    //cout<<"\n...max_index...."<<max_index;
      for(i=0;i<max_index;i++)
        sum1=sum1+a[i];

    //cout<<"......."<<sum1;
      for(i=max_index+1;i<n;i++)
        sum2=sum2+a[i];

    //cout<<"......."<<sum2;
      
      if((a[max_index]/eq_no) %2==0 )

        {
          if((sum1%eq_no || sum2%eq_no ) ==0)
        cout<<(((a[max_index] - eq_no -min(((sum1%eq_no)),((sum2%eq_no))))/2)+min(((sum1%eq_no)),((sum2%eq_no))))<<"\n";
        else if(sum1%eq_no ==0)
          cout<<(((a[max_index] - eq_no -min((sum1%eq_no),(eq_no-(sum2%eq_no))))/2)+min(((sum1%eq_no)),(eq_no-(sum2%eq_no))))<<"\n";
        else if(sum2%eq_no ==0)
          cout<<(((a[max_index] - eq_no -min((eq_no-(sum1%eq_no)),((sum2%eq_no))))/2)+min((eq_no-(sum1%eq_no)),((sum2%eq_no))))<<"\n";
        else
        cout<<(((a[max_index] - eq_no -min((eq_no-(sum1%eq_no)),(eq_no-(sum2%eq_no))))/2)+min((eq_no-(sum1%eq_no)),(eq_no-(sum2%eq_no))))<<"\n";
        }
      else
      {
       
        
        if((sum1%eq_no || sum2%eq_no ) ==0)
        cout<<(((a[max_index] - eq_no -min(((sum1%eq_no)),((sum2%eq_no))))/2)+min(((sum1%eq_no)),((sum2%eq_no))))<<"\n";
        else if(sum1%eq_no ==0)
          cout<<(((a[max_index] - eq_no -min((sum1%eq_no),(eq_no-(sum2%eq_no))))/2)+min(((sum1%eq_no)),(eq_no-(sum2%eq_no))))<<"\n";
        else if(sum2%eq_no ==0)
          cout<<(((a[max_index] - eq_no -min((eq_no-(sum1%eq_no)),((sum2%eq_no))))/2)+min((eq_no-(sum1%eq_no)),((sum2%eq_no))))<<"\n";
        else
        cout<<(((a[max_index] - eq_no -min((eq_no-(sum1%eq_no)),(eq_no-(sum2%eq_no))))/2)+min((eq_no-(sum1%eq_no)),(eq_no-(sum2%eq_no))))<<"\n";
          
      }
    }

 		t--;
 	}

return 0;

 }

