#include<iostream>
#include<cstdio>
#include<queue>
#define MAX 2000000000
using namespace std;
int a[30][30],n;
int b[30][30];//neeche
int c[30][30];//side
int d[30][30];//distance
priority_queue<pair<int,pair<int,int> > > q;
void dijikstra(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            d[i][j] = -MAX;
    d[0][0] = a[0][0];
    q = priority_queue<pair<int,pair<int,int> > >();
    q.push(make_pair(d[0][0],make_pair(0,0)));
    int x,y,temp,dist;
    while(!q.empty()){
        dist = q.top().first;
        x = q.top().second.first;
        y = q.top().second.second;
        q.pop();
        if(x==n-1 && y==n-1) break;
        if(dist > d[x][y]) break;
        //meeche
        if(y!=n-1){
            if(a[x][y+1]!=-1){
                temp = dist + a[x][y+1]-c[x][y];
                if(d[x][y+1]<temp){
                    d[x][y+1] = temp;
                    q.push(make_pair(temp,make_pair(x,y+1)));
                }
            }
        }
        //side
        if(x!=n-1){
            if(a[x+1][y] !=-1){
                temp = dist + a[x+1][y] - b[x][y];
                if(d[x+1][y] < temp){
                    d[x+1][y]  = temp;
                    q.push(make_pair(temp,make_pair(x+1,y)));
                }
            }
        }
    }
    if(d[n-1][n-1]<0)
        cout << "MURDER\n";
    else
        cout << d[n-1][n-1] << "\n";
}
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<2*n-1;i++){
            if(i%2){
            for(int j=0;j<n;j++)
                scanf("%d",&b[i/2][j]);
            }
            else{
            for(int j=0;j<n-1;j++)
                scanf("%d",&c[i/2][j]);
            }
        }
        dijikstra();
    }
}

