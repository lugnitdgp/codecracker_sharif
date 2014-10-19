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

void generate_answer(int a,int b,int c)
{
	float temp,r1,r2,r3;
	temp=(a+c)/2.0;
	r1=abs(temp-b);
	temp=(2*b-a);
	r2=abs(temp-c);
	temp=(2*b-c);
	r3=abs(temp-a);
	r1=min(r2,r1);
	r1=min(r1,r3);
	printf("%0.2f\n",r1);
}
int main()
{
	int T,a,b,c;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		si(a);
		si(b);
		si(c);
		generate_answer(a,b,c);
	}	
}