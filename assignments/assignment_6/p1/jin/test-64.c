
int t,i,l;
char word[30],t;
int counter=0;

printf("\nEnter Test case must be greater than 5 and lesser than 10");
scanf("%d",&t);

printf("Enter the value of R");
scanf("%d",&r);



if(t<5) || (t>10)
	printf("Enter valid test case");
else
{

for(i=0;i<t;i++)

if(r>0 && r<1000000009)
{	
	printf("Enter word");
	scanf("%s",word);
	
	l = word.length();
	counter=0;	
	for(i=0;i<l;i++)
	{
		if(word[i]>=65 && word[i]<=90) || (word[i]>=97 && word[i]<=122)
		{
			counter++;
		}
	}
	if(counter==0)
	{
		for(i=0;i<l;i++)
		{
			for(j=0;j<l;j++)
			{
				if(word[i]<word[j])
				{
					t = word[i];
					word[i]=word[j];
					word[j]=t;
				}
			}
		}
		
		printf("%c %d",word[r],r);		
	}
	
}
}
}