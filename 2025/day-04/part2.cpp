#include <iostream>
#include <queue>

#define N 135

using namespace std;

int main() {
    int rolls[N][N]{};
    int c, i = 0, j = 0;
    while (true) {
        c = getchar();
        if (c == EOF)
            break;
        else if (c == '\n')
            ++i, j = 0;
        else
            rolls[i][j++] = c == '@';
    }

    const int dirs[][2] = {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
        {1, 0}, {1, -1}, {0, -1}, {-1, -1}
    };

    queue<int> q;
    bool vis[N][N]{};
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (rolls[i][j]) {
                for (auto [di, dj] : dirs) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N)
                        rolls[i][j] += (bool) rolls[ni][nj];
                }
                if (rolls[i][j] < 5) {
                    q.push(i * N + j);
                    vis[i][j] = true;
                }
            }
        }
    }

    int ans = 0;
    while (!q.empty()) {
        i = q.front() / N, j = q.front() % N;
        q.pop();
        ++ans;
        for (auto [di, dj] : dirs) {
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < N && nj >= 0 && nj < N && rolls[ni][nj]) {
                if (--rolls[ni][nj] < 5 && !vis[ni][nj]) {
                    q.push(ni * N + nj);
                    vis[ni][nj] = true;
                }
            }
        }
    }
    cout << ans << endl;
}
