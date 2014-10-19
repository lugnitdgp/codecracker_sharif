#include<iostream>
#include<map>
using namespace std;

#define MAX9 1000000007
#define MAX6 1000005
#define MAX5 100005

#define sin(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sst(x) scanf("%s",x)

#define pin(x) printf("%d",x)
#define pll(x) printf("%lld",x)
#define pst(x) printf("%s",x)
#define nl() printf("\n")
#define psp() printf(" ")

#define fon(x,n) for(x=0;x<n;x++)

int main()
{
	int t,n,m,i,j,roll;
	string temp;
	char chr[50];
	sin(t);
	while(t--)
	{
		map<int,string> record;
		map<int,int> marks;
		sin(m); sin(n);
		fon(i,m)
		{
			sin(roll);
			getchar();
			getline(cin,temp);
			record[roll]=temp;
		}
		fon(i,n)
		{
			sin(roll);
			sin(j);
			if(marks[roll]<j)
				marks[roll]=j;
		}
		for( map<int, string>::iterator iter = record.begin();iter != record.end(); ++iter)
		{
		    roll=iter->first;
		    cout<<iter->second;
			psp();
		    cout<<marks[roll]<<endl;
		}
	}
	return 0;
}
