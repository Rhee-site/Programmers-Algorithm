#include<vector>
#include <queue>
using namespace std;

struct Pos {
    int y;
    int x;
    int dist;
};

int solution(vector<vector<int> > maps)
{
     int answer = -1;
    
    const int n = maps.size();
    const int m = maps[0].size();
    int deltaY[4] = { -1, 0, 1, 0 };
    int deltaX[4] = { 0, 1, 0, -1 };

    vector<vector<bool>> checked(n, vector<bool>(m));
    queue<Pos> q;

    q.push({0, 0, 1}); 
    checked[0][0] = true;

    while (!q.empty()) {
        Pos pos = q.front();
        q.pop();
        
        int nowY = pos.y;
        int nowX = pos.x;
        int now_dist = pos.dist;
        
        if (nowY == n - 1 && nowX == m - 1) 
            answer = now_dist;

        for (int i = 0; i < 4; ++i) {
            int nextY = nowY + deltaY[i];
            int nextX = nowX + deltaX[i];

            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
                continue;
            if (maps[nextY][nextX] == 0)
                continue;
            if (checked[nextY][nextX])
                continue;

            q.push({nextY, nextX, now_dist + 1}); 
            checked[nextY][nextX] = true;
        }
    }
        
    return answer;
}