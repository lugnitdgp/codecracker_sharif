//write your code here
#include <stdio.h>
#include <stdlib.h>
#include<string.h>


void sort(char *s)
{
   int c, d = 0, length;
   char *pointer, *result, ch;

   length = strlen(s);

   result = (char*)malloc(length+1);

   pointer = s;

   for ( ch = 'a' ; ch <= 'z' ; ch++ )
   {
      for ( c = 0 ; c < length ; c++ )
      {
         if ( *pointer == ch )
         {
            *(result+d) = *pointer;
            d++;
         }
         pointer++;
      }
      pointer = s;
   }
   *(result+d) = '\0';

   strcpy(s, result);
   free(result);
}


int main()
{
    int i,t,n, req,j;
    char word[27];
    long r,sum;
    scanf("%d", &t);
 while(t--){
    scanf("%d", &n);
    scanf("%s", &word);
    scanf("%ld",&r);
    sort(word);
    sum=0;
    req=0;

    for(i=1;sum<r;i*=n)
    {
        sum += n*i;
        req++;
    }
    int eliminated = sum - i;
    //printf("%ld   %d\n%s\n", eliminated,i,word);

    char newword[27];

    newword[req]='\0';

    for(j=req-1;j>=0;j--)   //i=eliminated;i<r;i++
    {
        for(i=0;i<req;i++)
        {
            newword[i] = word[0];
        }
       i=0;
       while(i<n)
       {
            if(eliminated==r-1)
            {
                printf("%s\n", newword);
                j=-1;
                break;
            }
            newword[j]=  word[++i];  //last letter under observation.
            eliminated++;
       }
    }
}
    return 0;
}
