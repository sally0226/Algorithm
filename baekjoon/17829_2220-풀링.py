import sys
input = sys.stdin.readline

N = int(input())
table=[]
for n in range(N):
    row = list(map(int, input().split()))
    table.append(row)

def recursive(n, startR, endR,startC, endC):
    if n==2:
        values = table[startR][startC:endC]+table[startR+1][startC:endC]
    else:
        values = []
        midR = (startR + endR)//2
        midC = (startC + endC)//2
        values.append(recursive(n//2, startR, midR, startC, midC))
        values.append(recursive(n//2, startR, midR, midC, endC))
        values.append(recursive(n//2, midR, endR, startC, midC))
        values.append(recursive(n//2, midR, endR, midC, endC))
    values.sort(reverse=True)
    return values[1]

print(recursive(N, 0, N, 0, N))