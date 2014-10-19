#include<iomanip>
#include<stack>
#include<iostream>
#include <cstdio>
#include <cstring>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

#define MAX_VAL 45
#define cin(n) scanf("%d",&n)
#define cinl(n) scanf("%lld",&n)
#define mp make_pair
#define inf 10000000
#define ill long long
#define pb push_back
#define mod 100000000
#define mn 1509
#define max2 100008
#define pz pair< pair<pair<int,int>,pair<int,int> >,pair<pair<int,int>,pair<int,int> > >
ill max(ill a,ill b)
{
	return a>b?a:b;
}
ill min(ill a,ill b)
{
	return a<b?a:b;
}
int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;

}

int main()
{
    int n,t,m,i,j,l;
    ill k,z,z1;

    cin(t);
    string s;
    set<char>st;
    while(t--)
    {
        st.clear();
        cin(n);
        cin>>s;
        for(i=0;i<n;i++)
            st.insert(s[i]);
        vector<char>v;
        v.clear();

        set<char>::iterator it;

        for(it=st.begin();it!=st.end();it++)
            v.pb(*it);
        cinl(k);
        string s1="";
        //k--;
        while(k>0)
        {
            k--;
            s1+=v[k%n];
            k/=n;
        }
        cout<<s1<<"\n";
    }
    return 0;
}
