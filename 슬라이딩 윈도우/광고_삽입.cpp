#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> logs_int;
priority_queue<int, vector<int>, greater<int>> pq;
int cache[360000];

int strToSec(string str) {
	int h = stoi(str.substr(0, 2));
	int m = stoi(str.substr(3, 2));
	int s = stoi(str.substr(6, 2));
	return h * 3600 + m * 60 + s;
}
string secToStr(int sec) {
	int h = sec / 3600;
	sec -= h * 3600;
	int m = sec / 60;
	sec -= m * 60;

	string result = "";
	if (h < 10)
		result += '0';
	result += to_string(h);
	result += ':';
	if (m < 10)
		result += '0';
	result += to_string(m);
	result += ':';
	if (sec < 10)
		result += '0';
	result += to_string(sec);

	return result;
}
string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";
	for (string log : logs) {
		int start = strToSec(log.substr(0, 8));
		int end = strToSec(log.substr(9));
		logs_int.push_back({ start,end });
        for (int i = start; i<end;i++) {
            cache[i]++;
        }
	}
    
	int play_time_int = strToSec(play_time);
	int adv_time_int = strToSec(adv_time);

	int log_size = logs.size();
	int answerT = 0;
	long maxCount = 0;
	long count = 0;
    
    for (int t=0;t<=play_time_int;t++) {
        if (t < adv_time_int) {
            count += cache[t];
        }
        else {
            if (maxCount < count) {
                maxCount = count;
                answerT = t-adv_time_int;
            }
            count -= cache[t-adv_time_int];
            count += cache[t];
        }
    }
	
	answer = secToStr(answerT);
	return answer;
}

