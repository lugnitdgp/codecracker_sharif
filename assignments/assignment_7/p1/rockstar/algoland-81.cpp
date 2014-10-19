#include<iostream>
#include<cstdio>
#include<queue>
#define MAX 2000000000
using namespace std;
int a[30][30],n;
int b[30][30];//neeche
int c[30][30];//side
int d[30][30];//distance
struct data{
    int first;
    pair<int,int> second;
    data(int a,int b,int c){
        first = a;
        second.first=b,second.second=c;
    }
    const bool operator<(const data  &d1)const{
        return first<d1.first;
    }
};
priority_queue<data > q;
void dijikstra(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            d[i][j] = MAX;
    d[0][0] = a[0][0];
    q = priority_queue<data>();
    q.push(data(d[0][0],0,0));
    int x,y,temp,dist;
    while(!q.empty()){
        dist = q.top().first;
        x = q.top().second.first;
        y = q.top().second.second;
        q.pop();
        if(x==n-1 && y==n-1) break;
        if(dist > d[x][y]) continue;
        //meeche
        if(y!=n-1){
            if(a[x][y+1]!=1){
                temp = dist + a[x][y+1]-c[x][y];
                if(d[x][y+1]>temp){
                    d[x][y+1] = temp;
                    q.push(data(temp,x,y+1));
                }
            }
        }
        //side
        if(x!=n-1){
            if(a[x+1][y] !=1){
                temp = dist + a[x+1][y] - b[x][y];
                if(d[x+1][y] > temp){
                    d[x+1][y]  = temp;
                    q.push(data(temp,x+1,y));
                }
            }
        }
    }
    if(d[n-1][n-1]>0)
        cout << "MURDER\n";
    else
        cout << -d[n-1][n-1] << "\n";
}
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
                a[i][j]*=-1;
            }
        for(int i=0;i<2*n-1;i++){
            if(i%2){
                for(int j=0;j<n;j++){
                    scanf("%d",&b[i/2][j]);
                    b[i/2][j] *= -1;
                }
            }
            else{
                for(int j=0;j<n-1;j++){
                    scanf("%d",&c[i/2][j]);
                    c[i/2][j] *= -1;
                }
            }
        }
        dijikstra();
    }
}

