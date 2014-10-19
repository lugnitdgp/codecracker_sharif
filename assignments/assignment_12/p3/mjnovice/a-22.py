t=int(raw_input())
while t:
    s=str(raw_input())
    n=len(s)
    t=""
    for i in xrange(0,n):
	t+="+"
    if n==t:
	print "NO"
    else:
	print "YES"
    t-=1