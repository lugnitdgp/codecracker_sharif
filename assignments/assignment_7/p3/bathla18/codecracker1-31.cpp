#include <iostream>
#include <cstdio>
int main()
{

    int test;
    scanf ( "%d", &test );
    while (test--){
        int n;
        scanf ( "%d", &n);
        int a;
        int min = 10000,max =0;
        for ( int i = 0; i < n; i++){
            scanf ( "%d", &a);
            if ( max < a){
                max = a;
            }
            if ( min > a ){
                min = a;
            }
        }
        if (( max - min )%2 == 0) {
            printf ( "%d\n", (max-min)/2);
        }else {
            printf ( "ANGRY\n");
        }
    }
    return 0;
}
