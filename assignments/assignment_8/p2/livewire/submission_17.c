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
char word[21];int z1;
z1=0;
//while(1)
//{
    scanf("%s",word);
    k=strlen(word);
    //printf("%d\n",k);
    //z++;
    //k=strlen(word[z1]);
    //if((word[z1][0]=='e'&&word[z1][1]=='n'&&word[z1][2]=='d')&&(k==3))
    //break;
    //z1++;
    //printf("cadsa\n");

//printf("xasdasad\n");
z=0;
    //printf("in b\n");
        flag=0;
        //k=strlen(word[z]);
        if((word[0]=='e'&&word[1]=='n'&&word[2]=='d')&&(k==3))
        return 0;

    for(i=0;i<(k-2);i++)
    {
        if((vow(word[i])&&vow(word[i+1])&&vow(word[i+2]))||((!vow(word[i]))&&(!vow(word[i+1]))&&(!vow(word[i+2]))))
        {
            printf("<%s> is not acceptable.\n",word);
            flag=1;
            break;
        }
        else if((word[i]==word[i+1])||(word[i+1]==word[i+2]))
        {
            if((word[i]==word[i+1])&&(word[i]!='e'&&word[i]!='o'))
            {
                 printf("<%s> is not acceptable.\n",word);
                 flag=1;
                 break;
            }
            else
            {
            	if((word[i+2]==word[i+1])&&(word[i+2]!='e'&&word[i+2]!='o'))
              {
                 printf("<%s> is not acceptable.\n",word);
                 flag=1;
                 break;
              }
            }
        }

    }
    //int vowel=0;
    if(flag==0)
    {
        for(i=0;i<(k);i++)
        {
            if(vow(word[i]))
                vowel=1;
        }
        if(vowel==1)
        {
            printf("<%s> is acceptable.\n",word);
        }
        else
        {
        	printf("<%s> is not acceptable.\n",word);
        }

    }




return 0;
}

