import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
parents = list(map(int, input().split()))
childs = [[] for _ in range(N+1)]

for idx in range(1,N): # 사장 제외
    childs[parents[idx]].append(idx+1)

scores = [0 for _ in range(N+1)]
for _ in range(M):
    i, w = map(int, input().split())
    scores[i]+=w

q = deque()
q.append(1)
while q:
    parent = q.popleft()
    for child in childs[parent]:
        scores[child] += scores[parent]
        q.append(child)

print(*scores[1:])

