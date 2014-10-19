/* Name- Aayush Agarwal
   Language -C++
   */
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <iterator>
#include <cassert>
#include <cctype>
#include <string>
#include <sstream>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#define fOr(i,n) for(int i=0;i<n;i++)
#define For(i,n) for(int i=1;i<=n;i++)
#define ss(a) scanf("%s",a)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define pi(a) printf("%d ",a)
#define pl(a) printf("%lld ",a)
#define ps(a) printf("%s ",a)
#define nl    printf("\n");
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
using namespace std;

const double eps=1e-9;
const double PI=2*acos(0.0);

#define VI vector<int>
#define VS vector<string>
#define VL vector<long long int>
#define VVI vector<VI>
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PSS pair<string,string>
#define PSI pair<string,int>
#define VPII vector<PII>
#define VPLL vector<PLL>
#define VPSS vector<PSS>
#define VPSI vector<PSI>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a<b)?a:b)

int arr[100][100];
int dp[100][100];
pair<int,int>arr2[100][100];

int main()
{
	int t,n,a;
	si(t);
	while(t--)
	{
		si(n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				si(arr[i][j]);
			}
		}
		for(int i=1;i<=(2*n)-1;i++)
		{
			if(i%2==1)
			{
				for(int j=1;j<=n-1;j++)
				{
					si(a);
					arr2[i/2+1][j].first=a;
				}
			}
			else
			{
				for(int j=1;j<=n;j++)
				{
					si(a);
					arr2[i/2][j].second=a;
					
				}
			}
		}
	/*	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				pi(arr2[i][j].first);
				pi(arr2[i][j].second);
				nl;
			}
		}*/
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=0;
			}
		}
		arr2[1][0]=mp(0,0);
		arr2[0][1]=mp(0,0);
		dp[1][1]=arr[1][1];
		for(int j=2;j<=n;j++)
		{
			if(arr[1][j]!=-1 && dp[1][j-1]!=-1)
			{
				dp[1][j]=arr[1][j]+(dp[1][j-1]-(arr2[1][j-1].first));
				if(dp[1][j]<0)
				dp[1][j]=-1;
				
			}
			else
			dp[1][j]=-1;
		}
		
		for(int j=2;j<=n;j++)
		{
			if(arr[j][1]!=-1 && dp[j-1][1]!=-1)
			{
				dp[j][1]=arr[j][1]+(dp[j-1][1]-(arr2[j-1][1].second));
				if(dp[j][1]<0)
				dp[j][1]=-1;
			}
			else
			dp[j][1]=-1;
		}
		
	/*	for(int j=1;j<=n;j++)
		pi(dp[1][j]);
		
		for(int j=1;j<=n;j++)
		pi(dp[j][1]);*/
		
		
		int ans,ans2;
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<=n;j++)
			{
				if(arr[i][j]!=-1)
				{  
				    //if(dp[i-1][j]!=-1 && dp[i-1][j]!=-1)
				    
				    
				    ans=dp[i-1][j]-arr2[i-1][j].second;
				    //else
				    //ans=INT_MIN;
				    //if(dp[i][j-1]!=-1)
				    ans2=dp[i][j-1]-arr2[i][j-1].first;
				    //else
				    //ans2=INT_MIN;
					//dp[i][j]=arr[i][j]+max(dp[i-1][j]-arr[i-1][j].first,dp[i][j-1]-arr[i][j-1].second);
					if(dp[i-1][j]!=-1 && dp[i][j-1]!=-1)
					{   
					    int ans3=max(ans,ans2);
						if(ans3==ans)
						dp[i][j]=arr[i][j]+ans;
						else
						dp[i][j]=arr[i][j]+ans2;
					}
					else if(dp[i][j-1]!=-1 && dp[i-1][j]==-1)
					dp[i][j]=arr[i][j]+ans2;
					else if(dp[i][j-1]==-1 && dp[i-1][j]!=-1)
					dp[i][j]=arr[i][j]+ans;
					else
					dp[i][j]=-1;
					if(dp[i][j]<0)
					dp[i][j]=-1;
					
				//	pi(dp[i][j]);
				}
				else
				dp[i][j]=-1;
				
			}
		}
		if(dp[n][n]==-1)
		printf("MURDER");
		else
		pi(dp[n][n]);
		nl;
	}
}