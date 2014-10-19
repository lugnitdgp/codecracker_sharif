#include<iostream>
#include<cstdio>

using namespace std;

#define MOD 1000000007
#define MAXN 1001

int ans[MAXN][MAXN]={0},sum[MAXN][MAXN]={0};

int main(){
    int i,j,n,k;
    for(i=1;i<MAXN;i++){
        ans[1][i]=1;
        sum[1][i]=1;
    }
    for(i=2;i<MAXN;i++){
        ans[i][i]=1;
        sum[i][i]=1;
        for(j=1;j<=i;j++)
            sum[i][j]+=sum[i-1][j];
        if(sum[i][i]==MOD)
            sum[i][i]=0;
        for(j=i+1;j<MAXN;j++){
            ans[i][j]=sum[i][j-i];
            sum[i][j]=sum[i-1][j]+ans[i][j];
            if(ans[i][j]>=MOD)
                ans[i][j]-=MOD;
            if(sum[i][j]>=MOD)
                sum[i][j]-=MOD;
        }
    }
    int t;
    scanf("%d", &t);
    for(i = 0; i < 6; i++){
    	for(j = 0; j < 6; j++){
    		//cout<<ans[i][j]<<" ";
    	}
    	//cout<<endl;
    }
    while(t--){
        scanf("%d%d", &n, &k);
        n -= 2;
        if(n < 0){
            printf("0\n");
        }
        else{
            printf("%d\n", ans[k][n]);
        }
    }
    return 0;
}

