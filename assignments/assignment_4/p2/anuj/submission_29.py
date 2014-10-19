#write your code here
t = (int)(raw_input())
for i in range (0, t):
	s = raw_input()
	res = 0
	l = len(s)
	#print l
	if(l<5): res = -1;
	else:
		if(s[0] !='l' and s[0] != 'L'): res = res+1
		if(s[1] !='i' and[1] != 'I'): res = res+1
		if(s[-1] !='x' and s[-1] != 'X'): res = res+1
		if(s[-2] !='u' and s[-2] != 'U'): res = res+1

		for x in range(2, l-2):
			#print s[x]
			#print s[0-x]
			if(s[x] != 'n' and s[x] !='N'): res = res+1
	print res