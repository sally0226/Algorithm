package DP

import "strings"

func solution(id_list []string, report []string, k int) []int {
	N := len(id_list)
	reportMap := make(map[string]bool)
	userReportedMap := make(map[string]int)   // [유저]:신고당한횟수
	reportingMap := make(map[string][]string) // [유저]: {내가신고한유저}
	for _, v := range report {
		if reportMap[v] {
			continue
		}
		reportMap[v] = true
		s := strings.Split(v, " ")
		userReportedMap[s[1]]++
		_, ok := reportingMap[s[0]]
		if !ok {
			reportingMap[s[0]] = make([]string, 0)
		}
		reportingMap[s[0]] = append(reportingMap[s[0]], s[1])
	}

	answer := make([]int, N, N)
	for i, id := range id_list {
		reporting := reportingMap[id]
		for _, v := range reporting {
			if userReportedMap[v] >= k {
				answer[i]++
			}
		}
	}
	return answer
}
