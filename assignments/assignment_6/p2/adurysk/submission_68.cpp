#include <iostream>
using namespace std;

#define MAXN 100000

int a[MAXN];
bool vis[MAXN];

inline void solve(){
	int n, i, j;
	cin>>n;
	for(i = 0; i < n; i++){
		cin>>a[i];
	}
	for(i = 0; i < n; i++){
		vis[i] = false;
	}
	j = a[0];
	for(i = 0; i < n; i++){
        if(j == 0){
            break;
        }
        if(vis[j] == true){
            break;
        }
        vis[j] = true;
        j = a[j];
	}
	if(j != 0 || vis[n - 1] == false){
        printf("HORRIBLE\n");
	}
	else{
        printf("%d\n", i + i - 1);
	}
    return;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
