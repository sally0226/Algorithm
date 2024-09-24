package BFS_DFS

var cache []bool
var w []string
var t string

func solution(begin string, target string, words []string) int {
	N := len(words)
	w = append(words, begin)
	cache = make([]bool, N+1, N+1)
	t = target

	answer := recursive(N, 0)
	if answer == 1000000 {
		answer = 0
	}
	return answer
}

func recursive(now int, cnt int) int {
	cache[now] = true

	answer := 1000000
	for i, v := range w {
		if cache[i] { // 이미 방문했으면 패스
			continue
		}
		if !canVisit(w[now], v) { // 방문할 수 없는 케이스 패스
			continue
		}
		if v == t {
			answer = cnt + 1
			break
		}
		answer = min(answer, recursive(i, cnt+1))
	}

	return answer
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func canVisit(a, b string) bool {
	diff := 0
	for i, _ := range a {
		if a[i] != b[i] {
			diff++
		}
	}
	return diff == 1
}
