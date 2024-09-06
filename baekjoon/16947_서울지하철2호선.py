# acmicpc.net/problem/16947

import sys
from collections import deque

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

def DFS(node, cnt):
    global visited, dist
    if visited[node]:
        if cnt - dist[node] >= 3: # 사이클 시작
            return node
        else:
            return -1
    visited[node] = 1
    dist[node] = cnt
    for nextNode in adjList[node]:
        cycleNode = DFS(nextNode, cnt+1)
        if cycleNode != -1:
            visited[node] = 2
            if node == cycleNode: # 사이클 시작점 도착(사이클 종료)
                return -1
            else:
                return cycleNode
    return -1
    
def BFS():
    q = deque()
    for i in range(0, N):
        if visited[i] == 2:
            q.append(i)
            dist[i] = 0
        else:
            dist[i] = -1
    while q:
        node = q.popleft()
        for nextNode in adjList[node]:
            if dist[nextNode] == -1:
                q.append(nextNode)
                dist[nextNode] = dist[node] + 1

N = int(input())
adjList = [[]for _ in range(N)]
visited = [0 for _ in range(N)]
dist = [0 for _ in range(N)]
for _ in range(N):
    a, b = map(int, input().split())
    adjList[a-1].append(b-1)
    adjList[b-1].append(a-1)

DFS(0, 0) # 사이클 찾기
BFS()

print(*dist)



