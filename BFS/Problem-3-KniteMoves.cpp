#include <bits/stdc++.h>
using namespace std;

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};

int bfs(int sx, int sy, int tx, int ty) {
    vector<vector<int>> dist(8, vector<int>(8, -1));
    queue<pair<int,int>> q;

    dist[sx][sy] = 0;
    q.push({sx, sy});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;

        if (x == tx && y == ty) return dist[x][y];

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return 0;
}

int main() {
    
    string a, b;
    while (cin >> a >> b) {
        int sx = a[0] - 'a';
        int sy = a[1] - '1';
        int tx = b[0] - 'a';
        int ty = b[1] - '1';

        int moves = bfs(sx, sy, tx, ty);

        cout << "To get from " << a << " to " << b
             << " takes " << moves << " knight moves.\n";
    }
}
