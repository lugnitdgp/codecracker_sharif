#include<iostream>
#include<cstdio>
using namespace std;
int arr[100005];

int main()
{
        int t,n,m,l,r,x;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d %d",&n,&m);
                for(int i=0;i<n;i++)
                {
                        scanf("%d",&arr[i]);
                }
                int cnt=0;
                while(m--)
                {
                        scanf("%d %d %d",&x,&l,&r);
                        l--;r--;
                        for(int i=l;i<=r;i++)
                        {
                                if(arr[i]==x)
                                cnt++;
                                
                        }
                        if(cnt)
                        printf("Yes %d\n",cnt);
                        else
                        printf("No %d\n",cnt);
                        
                }
        }
}