//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//using namespace std;


int main()
{

    int A[26],j,g,t,i,len;
    long long R,m,n;
    char S[26],L[26],D[1000000];
    scanf("%d",&t);
    while(t--)
    {
       //memset(A,0,sizeof(A));
       for(i=0;i<26;i++)
        A[i]=0;
        scanf("%d",&len);
        scanf("%s",S);
        for(i=0;i<len;i++)
        {
            A[S[i]-'a']++;
        }
        j=0;
        for(i=0;i<26;i++)
        {

                for(g=0;g<A[i];g++)
                {
                    if(A[i]>0)
                    L[j++]=(char)(97+i);

                }




        }



        scanf("%lld",&R);
        j=0;
        int b=len;
        while(R>b)
        {
            m=R%b;
            if(m>0)
                D[j++]=L[m-1];
            else
                D[j++]=L[b-1];

            R=R/b;

            //printf("m=%lld R=%lld C=%c\n",m,R,L[m-1]);


        }
        if(R>0 && R<len)
            D[j++]=L[R-1];


        for(i=j-1;i>=0;i--)
            printf("%c",D[i]);
        printf("\n");


    }

    return 0;
}
