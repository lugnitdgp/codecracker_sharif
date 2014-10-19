import sys
import itertools


def combinations(word, length):
    if (length <= 0): return
    for s in word:
        if len(s) <= length: yield s
        for t in combinations(word, length-len(s)): yield s+t


if __name__ == "__main__":
    t = int(raw_input())
    for i in xrange(t):
        length = int(raw_input())
        word = list(raw_input())
        n = int(raw_input())
        word.sort()
        comb = []
        for x in combinations(word, length):
            comb.append(x)
        
        comb.sort(key=lambda s:len(s))
        sys.stdout.write("%s\n" % (comb[n-1]))
