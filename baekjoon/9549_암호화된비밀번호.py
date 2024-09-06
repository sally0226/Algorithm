# https://www.acmicpc.net/problem/9549

import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    encPw = input()
    pw = input()

    m = dict()
    for c in encPw:
        if c in m:
            m[c] += 1
        else:
            m[c] = 1

    flag = True
    for c in pw:
        cnt = m.get(c, 0)
        if cnt < 1:
            flag = False
            break
        m[c] -= 1
    
    if flag:
        print("YES")
    else:
        print("NO")