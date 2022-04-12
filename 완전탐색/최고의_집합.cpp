#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n > s) return {-1};
    int num = s / n;
    answer = vector<int>(n, num);
    for (int i=0;i<s%n;i++) {
        answer[n-1-i]++;
    }
    return answer;
}