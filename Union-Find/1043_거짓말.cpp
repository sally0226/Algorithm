#include<iostream>
#include<vector>

using namespace std;

int N, M, P;
vector<int> know;
vector<int> parents;
vector<vector<int>> party;

int findParent(int a) {
    if (parents[a] == a) return a;
    return findParent(parents[a]);
}

void _union(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    parents[a] = b;
}

int main(){
    cin>> N >> M >> P;
    int answer = 0;
    party = vector<vector<int>>(M);
    for (int n=0;n<=N;n++) {
        parents.push_back(n);
    }
    for (int p=0;p<P;p++) {
        int temp;
        cin >> temp;
        know.push_back(temp);
    }

    for (int m=0;m<M;m++) {
        int num, temp, prev;
        cin >> num;
        cin >> prev;
        party[m].push_back(prev);
        for (int n=1;n<num;n++) {
            cin >> temp;
            _union(prev, num);
            prev = temp;
            party[m].push_back(temp);
        }
    }
    for (int m=0;m<M;m++) {
        bool flag = 0;
        for (auto person: party[m]) {
            if (flag) break;
            for (auto t:know) {
                if (findParent(person) == findParent(t)) {
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag) answer++;
    }
    cout <<answer<<endl;
    return 0;
}