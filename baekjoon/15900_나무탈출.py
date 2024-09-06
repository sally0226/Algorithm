import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

N = int(input())

adjList = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(int, input().split())
    adjList[a-1].append(b-1)
    adjList[b-1].append(a-1)

# 홀수 depth가 짝수개면 짐 
isWin = False
visited = [False for _ in range(N)]
def DFS(start, depth):
    global visited, isWin
    isLeaf = True
    for node in adjList[start]:
        if visited[node]:
            continue
        isLeaf = False
        visited[node]=True
        DFS(node, depth+1)
        visited[node]=False
    if isLeaf and depth%2 == 1:
        isWin = not isWin

visited[0] = True
DFS(0, 0)
if isWin:
    print("Yes")
else:
    print("No")


