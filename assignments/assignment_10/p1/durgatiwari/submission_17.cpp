#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

/*typedef long long int64;
typedef unsigned long long uint64;*/
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
/*template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}*/
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ll long long int
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define nl printf("\n")
#define pl(x) printf("%lld",x)

int main()
{
	int n,m,l,r,x,p,p1,f=0,f1=0,ma=-1,ma1=-1,T;
	si(T);
	while(T--){
		f=0;f1=0;ma=-1;ma1=-1;
		map<int,int>mp1,mp2;
		si(n);
		si(m);
		for(int i=0;i<m;i++)
		{
			si(l);
			si(r);
			si(x);
			mp1[l]+=x;
			mp2[r]+=x;
		}
		map<int,int>::iterator it;
		for(it=mp1.begin();it!=mp1.end();++it)
		{
			if(ma<it->second)
			{
				ma=it->second;
				f=0;
				p=it->first;
			}
			else if(ma==it->second)
			{
				f=1;
			}
		}
		for(it=mp2.begin();it!=mp2.end();++it)
		{
			if(ma1<it->second)
			{
				ma1=it->second;
				f1=0;
				p1=it->first;
			}
			else if(ma1==it->second)
			{
				f1=1;
			}
		}
		if(ma!=ma1)
		{
			if(ma>ma1&&f!=1)cout<<"Row"<<" "<<p<<endl;
			else if(ma<ma1&&f1!=1)cout<<"Column"<<" "<<p1<<endl;
			else cout<<"Bad luck"<<endl;
		}
		else cout<<"Bad luck"<<endl;
	}
}