//write your code here/* SUJAL MANDAL ss6sujal@gmail.com */

#include <iostream>
using namespace std;
int mastertheif(int[],int);
int theif(int[],int,int);
int testCase;
int switches[100][100];
int testSwitches[100];
int totalmoves;
int main(int argc, char** argv)
{
cout<<"Enter the number of Test cases\n";
cin>>testCase;
int numberRooms[testCase];
for(int i=0;i<testCase;i++)
{
	cout<<"Enter the number of Rooms for testcase number :"<<i+1<<"\n";
	cin>>numberRooms[i];
}

for(int i=0;i<testCase;i++)
{
for(int j=0;j<numberRooms[i];j++)
{
switches[i][numberRooms[j]];
cout<<"TestCase:"<<i<<"\nenter the room which contains the switch for the gate of room no :"<<j<<"\n";
cin>>switches[i][j];
}
}

for(int i=0;i<testCase;i++)
{
cout<<"\n\n";
for(int j=0;j<numberRooms[i];j++)
{
testSwitches[j]=switches[i][j];
}
totalmoves=mastertheif(testSwitches,numberRooms[i]);
if(totalmoves==-1)
cout<<"Horrible!\n";
else
{
cout<<"SOLUTION FOR TESTCASE:"<<i<<"\n";
cout<<"total number of moves to enter the diamonds room are:"<<totalmoves<<"\n";
}
}	
	return 0;
}


int mastertheif(int tempswitches[],int numberRooms)
{
	int temp;
	int count=0;
	int currentroom=0;
	if(tempswitches[numberRooms-1]==numberRooms-1)
	{
		return -1;
	}
	else
	{
	for(int i=0;i<numberRooms;i++)
	{
		count++;
		temp=theif(tempswitches,currentroom,numberRooms);
		if(temp==0)
		{
			return count;
		}
		else
		currentroom=temp;
	}
	}
}

int theif(int tempswitches[],int currentroom,int numberRooms)
{
	int temp;
	if(currentroom==numberRooms)
	{
		return 0;
	}
	else
	temp=tempswitches[currentroom];
	return temp;
}