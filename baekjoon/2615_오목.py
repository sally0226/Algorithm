# https://www.acmicpc.net/problem/2615

import sys
from collections import deque

input = sys.stdin.readline
N = 19

board = []
for _ in range(N):
    temp = input().split()
    board.append(temp)

# 가로, 세로, \, /
dr = [0, -1, -1, -1]
dc = [-1, 0, -1, 1]
visited = [[[False for _ in range(4)] for _ in range(N)] for _ in range(N)]

def BFS(r,c):
    global board, visiteds
    team = board[r][c]
    q = deque()
    for d in range(4):
        if not visited[r][c][d]:
            q.appendleft([r, c, 1, d]) # r, c, cnt, dir
            visited[r][c][d] = True
    
    while q:
        temp = q.pop()
        r = temp[0]
        c = temp[1]
        cnt = temp[2]
        dir = temp[3]
        nextR = r + dr[dir]
        nextC = c + dc[dir]

        if nextR < 0 or nextR >= N or nextC < 0 or nextC >= 19 or board[nextR][nextC] != team or visited[nextR][nextC][dir]:
            if cnt == 5:
                if dir == 3:
                    r += 4
                    c -= 4
                return team, r, c
            continue
        
        if cnt == 5: # 6목 이상을 체크할필요가 없음
            continue
        q.appendleft([nextR, nextC, cnt+1, dir])
        visited[nextR][nextC][dir] = True

    return 0, 0, 0

team, r, c = 0,0,0
for R in range(18, -1, -1):
    if team != 0:
        break
    for C in range(18, -1, -1):
        if board[R][C] == '0':
            continue
        team, r, c = BFS(R, C)
        if team != 0:
            break

print(team)
if team != 0:
    print(r+1,c+1)
    


