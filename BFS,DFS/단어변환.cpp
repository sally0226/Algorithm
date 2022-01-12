#include <string>
#include <vector>
#include <queue>

using namespace std;
bool isCanConvert(string begin, string target) {
    int count = 0;
    for(int i=0;i<begin.size();i++) 
        if (begin[i] != target[i]) count++;
    return count <= 1;
}
int BFS(string begin, string target, vector<string> words) {
    vector<bool> visited(words.size());
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    while(!q.empty()) {
        string temp = q.front().first;
        int count = q.front().second;
        q.pop();
        
        for(int i=0; i<words.size();i++) {
            if (visited[i]) continue;
            if (!isCanConvert(temp, words[i])) continue;
            if (words[i] == target) return count + 1;
            
            visited[i] = 1;
            q.push({words[i], count + 1});
        }
    }
    return 0;
    
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    answer = BFS(begin, target, words);
    return answer;
}
