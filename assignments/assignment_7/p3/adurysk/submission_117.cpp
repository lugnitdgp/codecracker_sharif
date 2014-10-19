#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

#define MAXN 100000

int c[MAXN], s[MAXN];
int n;
bool l[MAXN], r[MAXN];

int main(){
    int t, i, k, ans, a, j, ti;
    cin>>t;
    while(t--){
        scanf("%d\n", &n);
        ans = 0;
        for(i = 1; i <= n; i++){
            scanf("%d", &c[i]);
        }
        s[0] = 0;
        for(i = 1; i <= n; i++){
            s[i] = s[i - 1] + c[i];
        }
        a = s[n] / n;
        if(a * n != s[n]){
            printf("ANGRY\n");
            continue;
        }
        l[n] = false;
        r[n] = false;
        for(i = 1; i < n; i++){
            if(s[i] < i * a){
                l[i] = true;
                r[i] = false;
            }
            else if(s[i] > i * a){
                l[i] = false;
                r[i] = true;
            }
            else{
                l[i] = false;
                r[i] = false;
            }
        }
        i = 1;
        while(i < n){
            //cout<<i<<endl;
            if(l[i] == true){
                for(j = i + 1; j < n; j++){
                    if(l[j] == false){
                        break;
                    }
                }
                ti = 0;
                for(k = j - 1; k >= i; k--){
                    if(c[k + 1] == 0){
                        ti++;
                    }
                    else{
                        ti = max(0, ti - c[k + 1] + 1);
                    }
                    ans = max(ans, ti + k * a - s[k]);
                }
                i = j;
            }
            else if(r[i] == true){
                for(j = i + 1; j < n; j++){
                    if(r[j] == false){
                        break;
                    }
                }
                ti = 0;
                for(k = i; k < j; k++){
                    if(c[k] == 0){
                        ti++;
                    }
                    else{
                        ti = max(0, ti - c[k] + 1);
                    }
                    ans = max(ans, ti + s[k] - k * a);
                    //cout<<k<<" "<<ans<<" "<<k * a<<" "<<s[k]<<" "<<ti<<endl;
                }
                i = j;
            }
            else{
                i++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
