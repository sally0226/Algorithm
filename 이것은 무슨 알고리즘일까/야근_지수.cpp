#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    sort(works.begin(), works.end(), greater<int>());
    long long answer = 0;
    int max_idx = 0;
    int h;
    
    // 5 * 10^4
    while (max_idx < works.size() - 1) {
        while (max_idx < works.size() - 2 && works[max_idx] == works[max_idx+1]) {
            max_idx++;
        }
        h = works[max_idx] - works[max_idx+1];
        if ((max_idx+1)*h > n) break;
        n -= (max_idx+1)*h;
        max_idx++;
    }
    int val = works[max_idx];
    
    if ((max_idx+1)*val <= n) return 0;

    val -= n/(max_idx+1);
    n -= n/(max_idx+1) * (max_idx+1);
    
    answer += (long long)val*(long long)val*(long long)(max_idx+1-n);
    answer += (long long)(val-1)*(long long)(val-1)*(long long)n;
    
    // 5 * 10^4
    for (int i = max_idx+1;i<works.size();i++) {
        answer += (long long)(works[i]*works[i]);
    }
    return answer;
}