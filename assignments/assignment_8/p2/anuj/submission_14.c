#include<stdio.h>
#include<string.h>

int vow(char p)
{
    if(p=='a'||p=='e'||p=='i'||p=='o'||p=='u')
        return 1;
    return 0;
}

int main()
{
long long int i,j,k,l,m,n,t,z;
long long int flag=0,vowel=0;
char word[100][21];int z1;
z1=0;
while(1)
{
    scanf("%s",&word[z1]);
    k=strlen(word[z1]);
    //printf("%d\n",k);
    //z++;
    k=strlen(word[z1]);
    if((word[z1][0]=='e'&&word[z1][1]=='n'&&word[z1][2]=='d')&&(k==3))
    break;
    z1++;
    //printf("cadsa\n");
}
//printf("xasdasad\n");
z=0;
while(z<z1)
{
    //printf("in b\n");

        k=strlen(word[z]);
        if((word[z][0]=='e'&&word[z][1]=='n'&&word[z][2]=='d')&&(k==3))
        return 0;

    for(i=0;i<(k-2);i++)
    {
        if((vow(word[z][i])&&vow(word[z][i+1])&&vow(word[z][i+2]))||((!vow(word[z][i]))&&(!vow(word[z][i+1]))&&(!vow(word[z][i+2]))))
        {
            printf("<%s> is not acceptable.\n",word[z]);
            flag=1;
            break;
        }
        else if((word[z][i]==word[z][i+1])||(word[z][i+1]==word[z][i+2]))
        {
            if((word[z][i]==word[z][i+1])&&(word[z][i]!='e'&&word[z][i]!='o'))
            {
                 printf("<%s> is not acceptable.\n",word[z]);
                 flag=1;
                 break;
            }
            else
            {
            	if((word[z][i+2]==word[z][i+1])&&(word[z][i+2]!='e'&&word[z][i+2]!='o'))
              {
                 printf("<%s> is not acceptable.\n",word[z]);
                 flag=1;
                 break;
              }
            }
        }

    }
    int vowel=0;
    if(flag==0)
    {
        for(i=0;i<(k);i++)
        {
            if(vow(word[z][i]))
                vowel=1;
        }
        if(vowel==1)
        {
            printf("<%s> is acceptable.\n",word[z]);
        }
        else
        {
        	printf("<%s> is not acceptable.\n",word[z]);
        }

    }
    z++;

}

return 0;
}
