#include<iostream>
using namespace std;
#include<string.h>
#include<algorithm>
#include<stdio.h>
int main()
{
    int t,n,p,q;
    int petrol[21][21];
    int cost[21][21];
    int dp[21][21];
    memset(dp,0,sizeof(dp));
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                scanf("%d",&petrol[i][j]);
        }

        for(int i=0;i<2*n-1;i++)
        {
            if(i%2==0)
            {
                for(int j=0;j<n-1;j++)
                    scanf("%d",&cost[i][j]);
            }
            else
            {
                for(int j=0;j<n;j++)
                    scanf("%d",&cost[i][j]);
            }
        }

        dp[0][0] = petrol[0][0];
        for(int i=1;i<n;i++)
        {
            if(petrol[0][i]!=-1 && dp[0][i-1]-cost[0][i-1]>=0)
                dp[0][i] = dp[0][i-1] + petrol[0][i] - cost[0][i-1];
            else
                dp[0][i] = -1;
        }

        for(int i=1;i<n;i++)
        {
            if(petrol[i][0]!=-1 && dp[i-1][0]-cost[2*i-1][0]>=0)
                dp[i][0] = dp[i-1][0] + petrol[i][0] - cost[2*i-1][0];
            else
                dp[i][0] = -1;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(petrol[i][j]!=-1)
                {
                    if(dp[i-1][j]-cost[2*i-1][j]>=0)
                        p = dp[i-1][j]+petrol[i][j]-cost[2*i-1][j];
                    else
                        p=-1;

                    if(dp[i][j-1]-cost[2*i][j-1]>=0)
                        q = dp[i][j-1]+petrol[i][j]-cost[2*i][j-1];
                    else
                        q = -1;

                    dp[i][j] = max(p,q);
                }
                else
                    dp[i][j] = -1;
            }
        }

        if(dp[n-1][n-1]==-1)
            printf("MURDER\n");
        else
            printf("%d\n",dp[n-1][n-1]);

    }
    return 0;
}
