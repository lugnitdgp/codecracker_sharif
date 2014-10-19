def modexp(base, exp, mod):
    pow2=1
    ans=1
    while exp>0:
	ans=(ans*(base**(pow2*(exp&1))))%mod
	exp=exp>>1
	pow2*=2
    return ans

t=int(raw_input())
for i in xrange(0,t):
    n,k=raw_input().split()
    n=int(n)
    k=int(k)
    if n-1>=k:
	print int((modexp(2,n-1-k,1000000007)*(n-k)-(n-k-1))%1000000007)
    else:
	print int(modexp(2,n-1,1000000007))