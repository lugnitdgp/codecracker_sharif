#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;

int main()
{
	int t;
	cin>>t;
	stack<char> s;
	while(t--)
	{
		int n;
		cin>>n;
		char arr[n];
		cin>>arr;
		sort(arr,arr+n);
		int x;
		cin>>x;
	//	cout<<arr<<endl;
		while(x)
		{
			int p=x%n;
			if(p==0)
				p=n-1;
			else
				p--;
			s.push(arr[p]);
			x/=n;
		}
		while(s.size()>0)
		{
			cout<<s.top();
			s.pop();
		}
		cout<<endl;
	}
	return 0;
}