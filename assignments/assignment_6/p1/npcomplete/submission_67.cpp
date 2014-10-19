#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

char* numToColumn(int n, char* outstr, const char* baseset){
    char* p = outstr;
    int len;
    len = strlen(baseset);
    while(n){
        *p++ = baseset[0 + ((n % len == 0)? len : n % len) - 1];
        n = (n - 1) / len;
    }
    *p = '\0';
    return strrev(outstr);//strrev isn't ANSI C
}

char* incrWord(char* outstr, const char* baseset){
    char *p;
    int size,len;
    int i,carry=1;

    size = strlen(baseset);
    len = strlen(outstr);
    for(i = len-1; carry && i>=0 ;--i){
        int pos;
        pos = strchr(baseset, outstr[i]) - baseset;//MUST NOT NULL
        pos += 1;//increment
        if(pos == size){
            carry=1;
            pos = 0;
        } else {
            carry=0;
        }
        outstr[i]=baseset[pos];
    }
    if(carry){
        memmove(&outstr[1], &outstr[0], len+1);
        outstr[0]=baseset[0];
    }
    return outstr;
}
int main(){
	int t;
	unsigned long int R;
	cin>>t;
	while(t--)
	{
	int len=0;
	cin>>len;
    char *cset = new char[len+1];
    cin>>cset;

	sort(cset,cset+len);
    
    char buff[20];
    cin>>R;
    int i;
    for(i=1;i<R;++i)//1 origin
    	numToColumn(i, buff, cset);
    printf("%s\n", numToColumn(i, buff, cset));
    delete cset;
	}
    return 0;
}