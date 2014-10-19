#write your code here#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long int 

char ch[26];
LL p[40];

inline void solve(){
	LL n, r, i, j;
	string w;
	cin>>n>>w>>r;
	for(i = 0; i < n; i++){
		ch[i] = w[i];
	}
	sort(ch, ch + n);
	p[0] = 1;
	for(i = 1; i < 10; i++){
		p[i] = p[i - 1] * n;
	}
	i = 1;
	while(r > p[i]){
		r -= p[i];
		i++;
	}
	r--;
	w = "";
	for(j = 0; j < i; j++){
		w = ch[r % n] + w;
		r /= n;
	}
	cout<<w<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}