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
    int i,t,n, req=0,j;
    char word[27];
    long r,sum =0;
    scanf("%d %d %ld", &t);
 while(t--){
    scanf("%d %ld", &n, &r);
    scanf("%s", &word);
    sort(word);

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
       while(i<req-1)
       {
            if(eliminated==r-1)
            {
                printf("%s\n", newword);
                return 0;
            }
            newword[j]=  word[++i];  //last letter under observation.
            eliminated++;
       }
    }
}
    return 0;
}
