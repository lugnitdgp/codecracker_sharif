//write your code here
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
#define nl printf("\n");
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
 
 
/* 0 indicate losing position . Any other non-zero number denotes winning position*/
 

int grundy[10001],moves[105];
vector<int>v;
 
int main()
{

for(int i=1;i<=50;i++)
{
    moves[i]=(i*i);
}

int t,n,a,ans=0;
grundy[0]=0;
grundy[1]=1;
for(int i=2;i<=10000;i++)
{
for(int j=0;j<101;j++)
{
if(i-moves[j]>=0)
{
v.pb(grundy[i-moves[j]]);
}
}
sort(v.begin(),v.end());
int val=0;
for(int j=0;j<v.size();j++)
{   
if(val==v[j])
val++;
}
grundy[i]=val;
v.clear();
}
/*for(int i=0;i<10;i++)
pi(grundy[i]);
nl;*/
si(t);
assert(1<=t<=10);
while(t--)
{
si(n);
assert(1<=n<=1000);
ans=0;
for(int i=0;i<n;i++)
{
si(a);
assert(1<=a<=10000);
ans=ans^grundy[a];
}
if(ans)
printf("Aayush\n");
else
printf("Durga\n");
}
} 