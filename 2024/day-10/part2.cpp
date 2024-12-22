#include <iostream>

#define LEN 45

using namespace std;

const int dirs[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int dfs(char (*map)[LEN], int i, int j, char next) {
    if (i == -1 || j == -1 || i == LEN || j == LEN || map[i][j] != next)
        return 0;

    if (next == '9')
        return 1;

    int score = 0;
    for (auto [di, dj] : dirs)
        score += dfs(map, i + di, j + dj, next + 1);

    return score;
}

int main() {
    char map[LEN][LEN];
    int c, i = 0, j = 0;
    while (true) {
        c = getchar();
        if (c == '\n')
            ++i, j = 0;
        else if (c == EOF)
            break;
        else
            map[i][j++] = c;
    }

    int ans = 0;
    for (i = 0; i < LEN; ++i)
        for (j = 0; j < LEN; ++j)
            if (map[i][j] == '0')
                ans += dfs(map, i, j, '0');

    cout << ans << endl;
}
