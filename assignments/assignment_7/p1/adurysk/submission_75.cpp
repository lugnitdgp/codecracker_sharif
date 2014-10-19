#include<iostream>
#include<vector>
using namespace std;
#define INF -1
#define LL long long
#define PB push_back
#define MAXN 100

LL a[MAXN][MAXN],ans[MAXN][MAXN];
LL pet[MAXN][MAXN][2];

LL max(LL x,LL y)
{
    if(x<y) return y;
    return x;
}

int main()
{
    LL t,n,x;
    cin>>t;
    while(t--)
    {
              cin>>n;
              for(LL i=1;i<=n;i++)
                      for(LL j=1;j<=n;j++)
                              {
                                    cin>>a[i][j];
                              }
              for(LL i=1;i<=2*n-1;i++)
              {
                if(i%2 == 1)
                {
                    for(LL j=1;j<n;j++)
                    {
                        cin>>x;
                        pet[i / 2 + 1][j + 1][0] = x;
                    }
                }
                else
                {
                    for(LL j=1;j<=n;j++)
                    {
                        cin>>x;
                        pet[i / 2 + 1][j][1] = x;
                    }
                }
              }
              ans[1][1] = a[1][1];
              for(LL i=2;i<=n;i++)
              {
                  if(a[1][i] == -1) {ans[1][i] = INF;continue;}
                  if(ans[1][i-1]-pet[1][i][0] < 0) ans[1][i] = INF;
                  else
                    ans[1][i] = ans[1][i-1]-pet[1][i][0] + a[1][i];
              }
              for(LL i=2;i<=n;i++)
              {
                  if(a[i][1] == -1) {ans[i][1] = INF;continue;}
                  if(ans[i-1][1]-pet[i][1][1] < 0) ans[i][1] = INF;
                  else
                    ans[i][1] = ans[i-1][1]-pet[i][1][1] + a[i][1];
              }

              for(LL i=2;i<=n;i++)
              {
                  for(LL j=2;j<=n;j++)
                  {
                      if(a[i][j] == -1) {ans[i][j] = INF;continue;}
                      if(max(ans[i-1][j] - pet[i][j][1]  , ans[i][j-1]-pet[i][j][0]) < 0) ans[i][j] = INF;
                      else
                        ans[i][j] = max(ans[i-1][j] - pet[i][j][1]  , ans[i][j-1]-pet[i][j][0]) + a[i][j];
                  }
              }
              if(ans[n][n] <= 0) cout<<"MURDER"<<endl;
              else  cout<<ans[n][n]<<endl;
        }
    return 0;
}