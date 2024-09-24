package BFS_DFS

// BFS
// 큐에 넣기
// 방문여부 체크 (두번 방문할 일은 없음)
// 해당 위치를 방문하는데 걸린 cnt를 저장해야 함 (최소 cnt가 저장될 수 있게)

import "container/list"

// import "fmt"

var board []string
var cache [][]int

var moveR = []int{-1, 1, 0, 0} // 상하좌우
var moveC = []int{0, 0, -1, 1}

func solution(b []string) int {
	board = b
	R := len(b)
	C := len(b[0])
	cache = make([][]int, R, R)
	for i := range cache {
		cache[i] = make([]int, C, C)
	}

	startR, startC := findStart()
	cache[startR][startC] = 1

	q := NewQueue()
	q.Push([]int{startR, startC})

	answer := -1
	for !q.Empty() {
		now := q.Pop()
		cnt := cache[now[0]][now[1]]

		for i := 0; i < 4; i++ {
			nextR := now[0]
			nextC := now[1]
			for true {
				beforeR := nextR
				beforeC := nextC
				nextR = beforeR + moveR[i]
				nextC = beforeC + moveC[i]

				if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) || board[nextR][nextC] == 'D' {
					if board[beforeR][beforeC] == 'G' {
						return cnt
					}
					if cache[beforeR][beforeC] != 0 && cache[beforeR][beforeC] <= cnt+1 {
						break
					}
					cache[beforeR][beforeC] = cnt + 1
					// fmt.Println("push 1: ", beforeR, beforeC)
					q.Push([]int{beforeR, beforeC})
					break
				}

				//if board[nextR][nextC] == 'D' {
				//	if board[beforeR][beforeC] == 'G' {
				//		return cnt
				//	}
				//	if cache[beforeR][beforeC] != 0 && cache[beforeR][beforeC] <= cnt+1 {
				//		break
				//	}
				//	cache[beforeR][beforeC] = cnt + 1
				//	q.Push([]int{beforeR, beforeC})
				//	break
				//}
			}

		}
	}

	return answer
}

func findStart() (int, int) {
	for r, row := range board {
		for c, value := range row {
			if value == 'R' {
				return r, c
			}
		}
	}
	return 0, 0
}

type Queue struct {
	element *list.List
}

func NewQueue() *Queue {
	return &Queue{
		element: list.New(),
	}
}

func (q *Queue) Push(v []int) {
	q.element.PushBack(v)
}

func (q *Queue) Pop() []int {
	f := q.element.Front()
	if f == nil {
		return nil
	}
	return q.element.Remove(f).([]int)
}

func (q *Queue) Empty() bool {
	return q.element.Len() == 0
}
