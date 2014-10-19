mod=10**9 + 7
dp={}

def cat(n):
  p=1
  j=1
  while j<n:
    p=((4*j+2)*p)/(j+2)
    j=j+1
  return p

def fact(n):
  p=1
  while n>1:
    p=p*n
    n=n-1
  return p

def func(n,k):
  if (n%2==0):
    if (k==(n+2)/2):
      return n/2
    return n
  else:
    return n

def poly(n,k):
  if k==0:
    return 1
  if (n==3 or k>n-3):
    return 0
  if (k==n-3):
    return cat(n-2)
  if (k==1):
    return ((n*(n-3))/2)
  if n*1001+k in dp:
    return dp[n*1001+k]
  res=0;
  for i in range(3,(n+2)/2+1):
    cur=0
    for j in range(0,k):
      cur=(cur+(poly(i,j)*poly(n+2-i,k-j-1)));
    res=(res+(func(n,i)*cur));
  res=res/fact(k)
  dp[n*1001+k]=res
  return res

t=(int)(raw_input())
while t>0:
  s=raw_input()
  s=s.split(" ")
  print poly((int)(s[0]),(int)(s[1])-1)%mod
  t=t-1
