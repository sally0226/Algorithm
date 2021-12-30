#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {1, (int)gems.size()};
    vector<int> gem_codes; // int형태의 gems 배열
    map<string, int> codes;
    
    int code = 0;
    for (string gem: gems) {
        if (codes.count(gem)) 
            gem_codes.push_back(codes[gem]);
        else {
            codes[gem] = code;
            gem_codes.push_back(code++);
        }
    }
    vector<int> have(code);
    int end = 0;
    for (int i=0;i<gem_codes.size();i++) {
        bool flag = true;
        while(find(have.begin(), have.end(), 0) != have.end()) {
            // 모든 종류의 보석을 포함하기전에, 진열장이 끝나버린 경우를 구분하기 위함
            if (end >= gem_codes.size()) {
                flag = false;
                break;
            }
            have[gem_codes[end++]]++;
        }
        if (flag && end - (i + 1) < answer[1] - answer[0]) {
            answer[0] = i+1; answer[1] = end;
        }
        have[gem_codes[i]]--;
    }
    return answer;
}