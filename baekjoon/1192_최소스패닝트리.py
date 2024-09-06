import sys
import heapq
input = sys.stdin.readline

# Prim (프림) 알고리즘 
V, E = map(int, input().split())
adjList = [[] for _ in range(V+1)]
for _ in range(E):
    a, b, weight = map(int, input().split())
    adjList[a-1].append([weight, b-1])
    adjList[b-1].append([weight, a-1])
 
minHeap = [[0, 0]] # [방문할 정점, 가중치]
answer = 0
visitedCnt = 0
visited = [False for _ in range(V)]
while minHeap:
    if visitedCnt == V:
        break
    weight, next = heapq.heappop(minHeap)
    if not visited[next]:
        visited[next] = True
        answer += weight
        visitedCnt += 1
        # 힙에 방문 가능한 정점 추가
        for i in adjList[next]:
            heapq.heappush(minHeap, i)
 
print(answer)