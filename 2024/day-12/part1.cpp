#include <iostream>

#define LEN 140

using namespace std;

char garden[LEN][LEN];
bool visited[LEN][LEN]{false};
const int dirs[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int i, int j, int& area, int& perimeter) {
    visited[i][j] = true;
    ++area;
    perimeter += 4;
    for (auto [di, dj] : dirs) {
        int ni = i + di, nj = j + dj;
        if (ni >= 0 && ni < LEN && nj >= 0 && nj < LEN && garden[ni][nj] == garden[i][j]) {
            --perimeter;
            if (!visited[ni][nj]) { dfs(ni, nj, area, perimeter); }
        }
    }
}

int calcPrice(int i, int j) {
    int area = 0, perimeter = 0;
    dfs(i, j, area, perimeter);
    return area * perimeter;
}

int main() {
    int c, i = 0, j = 0;
    while (true) {
        c = getchar();
        if (c == '\n')
            ++i, j = 0;
        else if (c == EOF)
            break;
        else
            garden[i][j++] = c;
    }

    int ans = 0;
    for (i = 0; i < LEN; ++i)
        for (j = 0; j < LEN; ++j)
            if (!visited[i][j])
                ans += calcPrice(i, j);

    cout << ans << endl;
}
