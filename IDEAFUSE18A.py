t = int(input())
for i in range(0,t):
    beauiful = False
    n = int(input())
    count = 1
    total = 0
    while (total<=n):
        if (total==n):
            beauiful = True
        total = total + count
        count = count + 1
    if (beauiful):
        print "Case #{}: YES".format(i+1)
    else:
        print "Case #{}: NO".format(i+1)
