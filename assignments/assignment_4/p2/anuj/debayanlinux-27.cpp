#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#define INF 2000000000
#define MOD 1000000007
#define ull unsigned long long
#define loop(i, j, n)  for(int (i) = (j); i < n; i++)
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		string s;
		cin>>s;
		int len = s.length(), res=0, i;
		if(len < 5) res = -1;
		else {
			if(s[0] !='l' && s[0] != 'L') res++;
			if(s[1] !='i' && s[1] != 'I') res++;
			if(s[len-1] !='x' && s[len-1] != 'X') res++;
			if(s[len-2] !='u' && s[len-2] != 'U') res++;
			for(i=2; i<len-2; i++) {
				if(s[i] != 'n' && s[i] !='N') res++;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
