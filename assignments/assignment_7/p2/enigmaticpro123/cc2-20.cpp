#include <iostream>
#include <string.h>
#include <stdio.h>


using namespace std;

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}


 int main()
 {
 	int t,n,*a,temp,sm,i;

 	cin>>t;

 	while (t)
 	{

 		cin>>n;
    sm=0;
 		a=new int[n];
 		for(i=0;i<n;i++)
 			cin>>a[i];
    temp=n;
    insertionSort(a,n);
    if(n==1)
      cout<<a[0]<<"\n";
    else if(n==2)
      cout<<a[1]<<"\n";
    else if(n==3)
      cout<<(2*a[0] + a[1] +a[2])<< "\n";
    else
    {
      while (temp)
      {
        if(temp==2)
         { 
        sm=sm+a[1];
        break;
        }
        else if(temp==3)
        {
          sm= sm +(2*a[0] + a[1] +a[2]);
          break;
        }
        else
        {
          sm = sm + (a[temp-1] + 2*a[1] +a[0]);
          temp=temp-2;
        }





      }
      cout<<sm <<"\n";

    }


 		t--;
 	}

return 0;

 }

