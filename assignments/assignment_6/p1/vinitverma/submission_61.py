import itertools
def main():
    t=int(raw_input())
    for c in range(t):
        n=int(raw_input())
        mystr=raw_input()
        string=sorted(mystr)
        p=1
        r=int(raw_input())
        for i in itertools.count():
            p=p*n
            if r-p>0:
                r=r-p
            else:
                break
        st=""
        r=r-1
        q=n
        for j in range(i+1):
            l=r%q
            r=r/n
            st=string[l]+st
        print st



if __name__ == '__main__':
    main()
