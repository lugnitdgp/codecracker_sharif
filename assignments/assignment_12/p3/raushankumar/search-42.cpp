#include <iostream>
#include <string.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string input;
    cin>>input;
    int flag=0;
    for(int i=0;i<input.size();i++)
    {
      if((input[i]=='D')||(input[i]=='J')||(input[i]=='0'))
      {
	flag=1;
	break;
      }
    }
    if(flag)
    cout<<"YES\n";
    else
    cout<<"NO\n";
  }
  return 0;
}