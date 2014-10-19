#include<stdio.h>
#include<math.h>
int main()
{
  unsigned long long a,j; 
  int times;
  scanf("%d",&times);
  while(times--)
  {
                
                char s[20000]={0},std[5]={'u','m','a','n','k'},s2[20000]={0};
                int sac;
                scanf("%d", &sac);
                int sa;
                char word[27];
                //for (sa = 0; sa < sac; sa++)
                    scanf("%s", word);
                int i1, j1;
                for (i1 = 0; i1 < sac; i1++)
                {
                    for (j1 = 0; j1 < sac-1; j1++)
                    {
                        if (word[j1] > word[j1+1]){
                            int zw = word[j1];
                            word[j1] = word[j1+1];
                            word[j1+1] = zw;}
                    }
                }  
                std[0] = word[sac-1];
                for (i1 = 1; i1 < sac; i1++)
                    std[i1] = word[i1-1];   
                    //printf("%s\n", std);
                scanf("%llu",&a);
                unsigned long long   sum=0,i=1;
    while(a>sum)
    {
              
                sum=sum+pow(sac,i);
                i++;
    }
    i--;     
                                      
   unsigned long long ch=i;
 //  sum=sum-n;      //combination in that series is stored in sum
   while(i--)
    {
        
       s[i]=std[a%sac];
 //printf("%c",std[a%5]);
        if(a%sac==0) a--;
       a=a/sac;
     } 
    // printf("%d",j=ch-1);
     for(j=0;j<ch;j++)
        printf("%c",s[j]);
        printf("\n");        
   
 }
   
     return 0;
}
