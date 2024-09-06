import sys

input = sys.stdin.readline

N, H = map(int, input().split())

# 누적합 이용 
seok = [0 for _ in range(H)]
jong = [0 for _ in range(H)]
for n in range(N):
    temp = int(input())
    if n%2 == 0:
        seok[0]+=1 # 시작점(바닥)에서 +1
        seok[temp]-=1 # 종료점에서 -1
    else:
        jong[H-1]+=1 # 시작점(천장)에서 +1
        jong[H-temp-1]-=1 # 종료점에서 -1

# 석순, 종유석 누적합 계산
for h in range(1,H):
    seok[h] += seok[h-1]
    jong[H-h-1] += jong[H-h]

count = 0
min_val = N
for h in range(H):
    temp = seok[h]+jong[h]
    if min_val > temp:
        min_val = temp
        count = 1
    elif min_val == temp:
        count += 1

print(min_val, count)
        