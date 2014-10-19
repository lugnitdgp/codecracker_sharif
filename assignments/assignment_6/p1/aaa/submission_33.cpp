#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;


int main()
{

    int A[26],j,t,len;
    long long R,m,n;
    char S[26],L[26],D[10000];
    scanf("%d",&t);
    while(t--)
    {
        memset(A,0,sizeof(A));
        scanf("%d",&len);
        scanf("%s",S);
        for(int i=0;i<strlen(S);i++)
        {
            A[S[i]-'a']++;
        }
        j=0;
        for(int i=0;i<26;i++)
        {
            if(A[i])
                L[j++]=(char)(97+i);


        }
       // for(int i=0;i<j;i++)
         //   cout<<L[i]<<" ";
        j=0;
        scanf("%lld",&R);
        int b=strlen(S);
        while(R>b)
        {
            m=R%b;
            D[j++]=L[m-1];
            R=R/b;
           // cout<<"IN"<<L[m-1]<<endl;

        }
        if(R>0 && R<strlen(S))
            D[j++]=L[R-1];

       // for(int i=0;i<26;i++)
         //       L[i]
        for(int i=j-1;i>=0;i--)
            printf("%c",D[i]);
        printf("\n");
    //for(int i=0;i<strlen(S);i++)
      //  cout<<L[i];

    }

    return 0;
}
