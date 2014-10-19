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
            int l = 0,i = 0,n = 0, u = 0, x = 0;
            char str[1000];
            int c = 0;
            scanf ( "%s", str);
            if ( strlen(str) < 5){
                printf ( "-1\n");
            }else {
                if ( str[0] != 'l' && str[0] != 'L'){
                    c++;
                }
                if ( str[1] != 'i' && str[1] != 'I'){
                    c++;
                }
                if ( str[strlen(str)-2] != 'u' && str[strlen(str)-2] != 'U'){
                    c++;
                }
                if ( str[strlen(str)-1] != 'x' && str[strlen(str)-1] != 'X'){
                    c++;
                }
                for ( int i = 2; i < strlen(str)-2; i++){
                    if ( str[i] != 'n' && str[i] != 'N'){
                        c++;
                    }
                }
                printf ( "%d\n", c );
            }
        }
        return 0;
}


