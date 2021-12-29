#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<string> user_ids;
vector<string> banned_ids;
unordered_set<int> bitmaps;

void recursive(int idx, int bitmap) {
    regex re(banned_ids[idx]);
    for (int i=0;i<user_ids.size();i++) {
        if (bitmap & (1<<i)) continue;
        if (regex_match(user_ids[i], re)) {
            bitmap += (1<<i);
            if (idx == banned_ids.size()-1) {
                bitmaps.insert(bitmap);
                continue;
            }
            recursive(idx+1, bitmap);
            bitmap -= (1<<i);
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    user_ids = user_id; banned_ids = banned_id; // 전역변수로 만들기
    // 정규식형태로 만들기 (^문자열.$)
    for (int i=0;i<banned_ids.size();i++) {
        banned_ids[i].insert(0,"^");
        replace(banned_ids[i].begin(), banned_ids[i].end(), '*', '.');
        banned_ids[i] += "$";
    }
    recursive(0,0);
    int answer = bitmaps.size();
    return answer;
}