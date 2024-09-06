import sys
input = sys.stdin.readline

N, d, k, c = map(int, input().split())
susiList = []
for _ in range(N):
    susi = int(input())
    susiList.append(susi)

answer=0
cnt = 0
hasCoupon = False
susiDict = dict()
for idx in range(-k+1, N-k+1):
    if idx == -k+1:
        for j in range(-k+1, 1):
            temp = susiList[j]
            if susiDict.get(temp, 0):
                susiDict[temp]+=1
            else:
                susiDict[temp]=1
                cnt+=1
            if temp == c:
                hasCoupon = True
        answer = cnt
        if not hasCoupon:
            answer+=1
        continue

    frontSusi = susiList[idx-1]
    susiDict[frontSusi]-=1
    if susiDict[frontSusi] == 0:
        cnt-=1
    if susiDict.get(c, 0) ==0:
        hasCoupon = False

    nextSusi = susiList[idx+k-1]
    if susiDict.get(nextSusi, 0):
        susiDict[nextSusi]+=1
    else:
        susiDict[nextSusi]=1
        cnt+=1
    if nextSusi == c:
        hasCoupon = True
    
   
    if not hasCoupon:
        answer = max(answer, cnt+1)
    else:
        answer = max(answer, cnt)

print(answer)