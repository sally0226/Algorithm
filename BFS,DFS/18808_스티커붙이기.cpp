#include<iostream>
#include<vector>

using namespace std;

int N, M, K;
vector<vector<int>> board;

// 0: 불가, 1: 가능, 2: row초과, 3: col초과
int canPut(int startR, int startC, vector<vector<int>> sticker, int sR, int sC) {
    int endR = startR + sR;
    int endC = startC + sC;
    if (endR > N) return 2; // row 초과
    if (endC > M) return 3; // col 초과

    for (int r = 0; r <sR;r++ ){
        for (int c=0;c<sC;c++) {
            if (sticker[r][c] && board[startR+r][startC+c]) return 0;
        }
    }
    return 1;
}

void put(int startR, int startC, vector<vector<int>> sticker, int sR, int sC) {
    for (int r = 0; r <sR;r++ ){
        for (int c=0;c<sC;c++) {
                board[startR+r][startC+c] = board[startR+r][startC+c] || sticker[r][c];
        }
    }
}

// 오른쪽으로 90도 회전
vector<vector<int>> rotate(vector<vector<int>> origin) {
    int newR = origin[0].size();
    int newC = origin.size();
    vector<vector<int>> newVer(newR, vector<int>(newC));

    for (int r = 0; r<newR;r++){
        for (int c=0;c<newC;c++) {
            newVer[r][c] = origin[newC - 1 - c][r];
        }
    }
    return newVer;
}

int main() {
    int answer = 0;
    cin >> N >> M >> K;
    board = vector<vector<int>>(N, vector<int>(M));
    for (int k=0; k<K; k++) {
        int R, C;
        int cnt = 0;
        cin >> R >> C;
        vector<vector<int>> sticker(R, vector<int>(C));
        for (int r=0; r<R; r++) {
            for (int c=0; c<C; c++) {
                cin >> sticker[r][c];
                if (sticker[r][c] == 1) cnt++;
            }
        }
        int flag;
        for (int i=0;i<4;i++) {
            flag = 0;
            for (int n=0;n<N;n++) {
                if (flag == 1 || flag == 2) break;
                for (int m=0;m<M;m++) {
                    flag = canPut(n, m, sticker, sticker.size(), sticker[0].size());
                    if (flag == 1) {
                        put(n, m,sticker, sticker.size(), sticker[0].size()); 
                        answer+=cnt;
                    }
                    if (flag > 0) break;
                }
            }
            if (flag == 1) break;
            if (i < 3) sticker = rotate(sticker);
        }
    }
    cout << answer << endl;
    return 0;
}