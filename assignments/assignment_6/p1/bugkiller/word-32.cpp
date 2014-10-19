#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <vector>
#include <iterator>
#include <set>
#include <bitset>
#include <ctime>
#include <iomanip>
#include <map>

using namespace std;

int a[26];

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) {
		int l, r, n = 0;
		cin>>l;
		string s;
		cin>>s;
		vector<char> c;
		cin>>r;
		memset(a, 0, sizeof(a));
		for(int i=0; i<l; i++)		if(!a[s[i] - 'a'])		a[s[i] - 'a']++;
		for(int i=0; i<26; i++) {
			if(a[i]) {
				c.push_back(i + 'a');
				n++;
			}
		}
		sort(c.begin(), c.end());
		//for(vector<char>::iterator i = c.begin(); i != c.end(); i++)	cout<<*i;
		//cout<<"\n";
		int p = (r/l)+1, q = r%l;
		if(!q)	p--, q = l-1;
		//cout<<p<<" "<<q<<"\n";
		while(p--)		cout<<c[q-1];
		cout<<"\n";
	}
	return 0;
}