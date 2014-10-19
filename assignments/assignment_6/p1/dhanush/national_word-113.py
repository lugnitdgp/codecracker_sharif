import sys
import itertools


def iterator(word, n):
    return [i for i in itertools.product(word, repeat=n)]


if __name__ == "__main__":
    t = int(raw_input())
    for i in xrange(t):
        length = int(raw_input())
        word = list(raw_input())
        r = int(raw_input())
        word.sort()
        ans = []
        for i in xrange(1, length+1):
           comb = iterator(word, i)
           ans += comb
           if len(ans) < r:
               continue
           else:
               s = ans[r-1]
               a = ""
               for i in s:
                   a += i
               print a
               break

