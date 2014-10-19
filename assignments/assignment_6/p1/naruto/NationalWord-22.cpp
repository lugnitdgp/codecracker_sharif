#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <time.h>
#include <map>
#include <stack>
#include <string>
#include <climits>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define LD long double
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define ss(n) scanf("%s",n)
#define pnl printf("\n")
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define CL(a,b) memset(a,b,sizeof(a))
#define GOLD ((1+sqrt(5))/2)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps (char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
void swapi(int *a,int *b){int temp;temp=*a;*a=*b;*b=temp;}
ULL gcd(ULL a,ULL b){if(a==0)return b;if(b==0)return a;if(a==1||b==1)return 1;
if(a==b)return a;if(a>b)return gcd(b,a%b);else return gcd(a,b%a);}
int L,I;
string W;
LL Calc(int N,int P)
{
	if(P==0)
		return 1;
	LL Res = Calc(N,P/2);
	if(P&1)
		return Res*Res*N;
	else
		return Res*Res;
}
string generate(int idx,int len,int characters)
{
	string str;
	LL Res = 1;
	for(int i = 1;i<len;i++)
	{
		Res = Res*characters;
	}
	for(int i = len-1;i>=0;i--)
	{
		str+=char(idx/Res + '0');
		idx%=Res;
		Res/=characters;
	}
	return str;
}
int main() 
{
	int Cases = 1;
	cin>>Cases;
	for(int Case = 0;Case<Cases;Case++)
	{
		cin>>L;
		cin>>W;
		cin>>I;
		I-=1;
		string str;
		sort(W.begin(),W.end());
		for(int i = 1;;i++)
		{
			LL Res = Calc(L,i);
			if(Res<=I)
				I-=Res;
			else
			{
				str = generate(I,i,L);
				break;
			}
		}
		for(int i = 0;i<str.length();i++)
			str[i] = W[str[i]-'0'];
		cout<<str<<endl;

	}
	return 0;
}