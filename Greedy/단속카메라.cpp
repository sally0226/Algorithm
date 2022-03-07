#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}
// 항상 진입 시점 <= 진출 시점
int solution(vector<vector<int>> routes) {
    // 진출시점이 빠른 순으로 정렬
    sort(routes.begin(), routes.end(),compare);

    int count = 0;
    int camera = -30001;
    // 진출시점에 카메라 설치 
    for (auto route: routes) {
        if (!(camera >= route[0] && camera <= route[1])) {
            count++;
            camera = route[1];
        }
    }
    int answer = count;
    return answer;
}