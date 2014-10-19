#include<stdio.h>
#include<string.h>
#include<math.h>
int n,t,sum,i,j,k,len,flag,diff;
int row;
char ans[205],str[205],res[205][205];
int main()
{
    while(1)
    {
        scanf("%d",&n);//n is the number of column
        if(n==0)
        break;
        scanf("%s",str);
        len=strlen(str);
        row=len/n;
        //diff=(row*n)-len;
        k=0;
        memset(res,0,sizeof(res));
        flag=0;
        for(i=0;i<row;i++)
         {
             if(flag==0)
             {for(j=0;j<n;j++)
             {res[i][j]=str[k];
             k++;}
             flag=1;
             }
             else if(flag==1)
             {
                 for(j=n-1;j>=0;j--)
                 {
                     res[i][j]=str[k];
                     k++;
                 }
                 flag=0;
             }
         }
         //printf("%s\n",res[1]);
         k=0;
         for(i=0;i<n;i++)
            {
                for(j=0;j<row;j++)
                {
                    if(res[i][j]!='x')
                    {ans[k]=res[i][j];k++;
                    printf("%c",ans[k]);}
                }
            }
            ans[k]='\0';
        printf("%s\n",ans);
    }
    return 0;
}