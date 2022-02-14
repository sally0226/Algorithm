import "sort"
var parents []int
func solution(n int, costs [][]int) int {
    answer := 0
    parents = make([]int, n+1) 
    for i:=0;i<n;i++ {
        parents[i] = i;
    }
    // costs 오름차순 정렬
    sort.Slice(costs, func (i, j int) bool {
            return costs[i][2] < costs[j][2]
    })
    
    for _, route:= range(costs) {
        if union(route[0], route[1]) {
            answer += route[2]
        }
    }
    return answer
}

// 최상위 부모 찾기
func find(a int) int {
    if a == parents[a] {
        return a
    }
    parents[a] = find(parents[a])
    return parents[a]
}

func union(a, b int) bool {
    a = find(a)
    b = find(b)
    
    if (a == b) {
        return false
    }
    // 합쳐주기
    if (a > b) {
        parents[a] = b // 작은애를 큰 애한테 달기
    } else {
        parents[b] = a
    }
    return true
}

