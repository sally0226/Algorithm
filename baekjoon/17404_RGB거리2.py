import sys
input = sys.stdin.readline

N = int(input())

costs = []
for _ in range(N):
    temp = list(map(int, input().split()))
    costs.append(temp)

answer = 10000000 # 1000*1000보다 크게
for firstColor in range(3):
    cache = [[0,0,0] for _ in range(N)]
    cache[0][firstColor] = costs[0][firstColor]
    cache[0][(firstColor+1)%3] = 1001 #집을 칠하는 최대 비용 1000
    cache[0][(firstColor+2)%3] = 1001

    for i in range(1,N):
        # R
        cache[i][0] = min(cache[i-1][1], cache[i-1][2]) + costs[i][0]
        # G
        cache[i][1] = min(cache[i-1][0], cache[i-1][2]) + costs[i][1]   
        # B
        cache[i][2] = min(cache[i-1][0], cache[i-1][1]) + costs[i][2]

    answer = min(answer, cache[N-1][(firstColor+1)%3], cache[N-1][(firstColor+2)%3])

print(answer)


