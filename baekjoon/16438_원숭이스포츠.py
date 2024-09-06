import sys
input = sys.stdin.readline

N = int(input())

answer = []

str = list("A"*N)
count = 0
def reverse(c):
    if c =="A":
        return "B"
    return "A"
def recursive(start, end):
    if end-start <= 1:
        return
    global str, count
    mid = (start + end)//2
    for idx in range(mid, end):
        str[idx] = reverse(str[idx])
    print(''.join(str))
    count+=1
    recursive(start, mid)
    recursive(mid, end)

recursive(0, N)
for _ in range(count, 7):
    print(''.join(str))