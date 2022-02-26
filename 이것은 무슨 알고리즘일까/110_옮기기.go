import (
    "strings"
)
func findLast0(str string) int {
	for i := len(str) - 1; i >= 0; i-- {
		if str[i] == '0' {
			return i
		}
	}
	return -1
}

func solution(s []string) []string {
	answer := make([]string, len(s))
	for idx, input := range s {
		count := 0

        str := ""
        for i:=0;i<len(input);i++ {
            str = str + string(input[i])
            if len(str) >= 3 {
                if str[len(str)-3:len(str)] == "110" {
                    count++
                    str = str[0:len(str)-3]
                }
            }
        }
        
		// 찾은 "110"들을 제일 마지막 0뒤에 붙이기
		zeroIdx := findLast0(str)
		
        sb := strings.Builder{}
		sb.Write([]byte(str[0 : zeroIdx+1]))
		for j := 0; j < count; j++ {
			sb.Write([]byte("110"))
		}
		sb.Write([]byte(str[zeroIdx+1:]))
		str = sb.String()
		answer[idx] = str
	}
	return answer
}

