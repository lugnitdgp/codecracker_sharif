t=int(raw_input())
while t:
    s=str(raw_input())
    if 'D' in s or 'J' in s or '0' in s:
	print "YES"
    else:
	print "NO"
    t-=1