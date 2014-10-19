// ANKUR MAHIWAL IT MNNIT Allahabad

#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>

#define L1(n) for(int i=0;i<n;i++)
#define L2(n,m) for(int i=0;i<n;i++) { for(int j=0;j<m;j++){

			
using namespace std;


int main()
{
	int t;
	int n;
	vector<char> att,aff;
	string arr;

	cin >> t;

		while(t--)
		{	att.clear();
			aff.clear();
			cin >> n;
			cin >> arr;
			for(int i=0;i<n;i++)
				att.push_back(arr[i]);

			sort(att.begin(),att.end());


			//for(int i=0;i<n;i++)
			//	cout << att[i];
			long long int find;
			cin >> find;
			long long int t=find;
			for( ;t>0;t=((t-1)/n))
			{
		aff.push_back(att[(t-1)%n]);
			}

for(int i=aff.size()-1;i>=0;i--)
	cout << aff[i];

cout << endl;



		}

return 0;
}
