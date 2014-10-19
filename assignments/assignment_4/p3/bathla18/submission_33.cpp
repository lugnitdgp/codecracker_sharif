#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main()
{

        int t;
        scanf ( "%d", &t);
        while ( t-- ){
                int a[7];
                for ( int i = 0; i < 7; i++){
                    a[i] = 0;
                }
                int u;
                for ( int i = 1; i < 6; i++){
                    scanf ( "%d", &u );
                    a[u]++;
                }
                int max = 0;
                for ( int i = 1; i < 7; i++ ){
                    if ( max < a[i]*i){
                        max = a[i]*i;
                    }
                }
                printf ( "%d\n", max);
        }
    return 0;
}
