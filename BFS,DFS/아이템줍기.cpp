#include <string>
#include <vector>
#include <queue>

using namespace std;

int board[110][110];

void fillBoard(vector<vector<int>> rectangle) {
    for (vector<int> item: rectangle) 
        for (int x=item[0]*2; x<=item[2]*2; x++) 
            for (int y=item[1]*2;y<=item[3]*2;y++) 
                board[y][x] = 1;
    for (vector<int> item: rectangle) 
        for (int x=item[0]*2+1; x<item[2]*2; x++) 
            for (int y=item[1]*2+1;y<item[3]*2;y++) 
                board[y][x] = 0;
}
struct Node {
    int x; int y; int count;
};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int BFS(int cX,int cY, int iX, int iY) {
    queue<Node> q;
    q.push({cX, cY, 0});
    board[cY][cX] = 2;
    while (!q.empty()) {
        Node temp = q.front();
        q.pop();
        
        for (int i=0;i<4;i++) {
            int newX = temp.x + dx[i];
            int newY = temp.y + dy[i];
            if (newX < 0 || newX > 100 || newY < 0 || newY > 100) continue;
            if (board[newY][newX] != 1) continue;
            if (newX == iX && newY == iY) 
                return (temp.count+1)/2;
            board[newY][newX] = 2;
            q.push({newX, newY, temp.count+1});
        }
    } 
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    fillBoard(rectangle);
    answer = BFS(characterX*2, characterY*2, itemX*2, itemY*2);
    return answer;
}
