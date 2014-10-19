
#include <algorithm>
#include <iomanip>
#include <complex>
#include "assert.h"
#include <cstdio>
#include <stack>
#include <time.h>
#include <cstdlib>
#include <ctype.h>
#include <climits>
#include <cctype>
#include <queue>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <numeric>
#include <set>
#include <unistd.h>
#include <bitset>
using namespace std;




int g[25][25];

bool solve(vector<vector<int> > &vis, int x, int y, int N){
        if(x >= N || y >= N) return 0;
        if(g[x][y] == -1) return 0;
        if(x == N-1 && y == N-1 ) return 1;

        if(vis[x+1][y] == -1)
         vis[x+1][y] = solve(vis,x+1,y,N);
        if( vis[x][y+1] == -1)
         vis[x][y+1] = solve(vis,x,y+1,N);

       return vis[x][y+1] || vis[x+1][y];
    }

int main(){

   #ifdef _FOOLS_SYS_
      freopen("input.txt","r",stdin);
   #else
     // ios_base::sync_with_stdio(false);
   #endif
   int T;

   cin>>T;
   while(T-->0){
     int N;
     cin>>N;

     for(int i = 0; i < N; ++i)
       for(int j = 0; j < N; ++j)
         cin>>g[i][j];

    map<pair< pair<int,int>, pair<int,int> >,int > mp;

     for(int i = 0; i < N; ++i){
        for(int j = 0; j < N - 1; ++j){
          int cur;
          cin>>cur;
          mp[make_pair(  make_pair(i,j),make_pair(i,j+1)  )] = cur;
        }

        if(i+1 < N)
        for(int j = 0; j < N ; ++j){
            int cur;
          cin>>cur;
          mp[make_pair(make_pair(i,j),make_pair(i+1,j))] = cur;
        }

      }

      vector<vector<int> > visited(22,vector<int>(22,-1));
      if(!solve(visited,0,0,N)){
        cout<<"MURDER";
        continue;
      }
     bool flg = 0;
     for(int i = N-1; i >= 0; --i){
           for(int j = N-1; j >= 0; --j){
               int c1 = INT_MIN;
               if(i+1 < N &&  g[i+1][j] != -1)
                  c1 = g[i+1][j] - mp[make_pair(make_pair(i,j),make_pair(i+1,j))];
               int c2 = INT_MIN;
               if(j+1 < N && g[i][j+1] != -1)
                  c2 = g[i][j+1] - mp[make_pair(make_pair(i,j),make_pair(i,j+1))];
               if(c1 != INT_MIN || c2 != INT_MIN)
               g[i][j] += max(c1,c2);
           }
         flg = 0;
         for(int j = N-1; j >= 0; --j)
            if(g[i][j] > 0) flg = 1;
         if(!flg) break;

     }



       if(flg)
        cout<<g[0][0]<<"\n";
       else
         cout<<"MURDER";
   }

   return 0;
}










