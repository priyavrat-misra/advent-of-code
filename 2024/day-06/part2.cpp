#include <iostream>
#include <unordered_set>
#include <vector>

#define LEN 130

using namespace std;

enum Dir { N = 0, E, S, W };

bool isCyclePresent(char (*map)[LEN], int i, int j) {
    vector<unordered_set<int>> m(4);
    Dir dir = N;
    while (i >= 0 && i < LEN && j >= 0 && j < LEN) {
        switch (dir) {
            case N:
                while (i >= 0 && map[i][j] != '#') {
                    if (m[dir].count(i * LEN + j)) { return true; }
                    else { m[dir].insert(i * LEN + j), --i; }
                }
                if (i >= 0) { ++i, ++j, dir = E; }
                break;
            case E:
                while (j < LEN && map[i][j] != '#') {
                    if (m[dir].count(i * LEN + j)) { return true; }
                    else { m[dir].insert(i * LEN + j), ++j; }
                }
                if (j < LEN) { --j, ++i, dir = S; }
                break;
            case S:
                while (i < LEN && map[i][j] != '#') {
                    if (m[dir].count(i * LEN + j)) { return true; }
                    else { m[dir].insert(i * LEN + j), ++i; }
                }
                if (i < LEN) { --i, --j, dir = W; }
                break;
            case W:
                while (j >= 0 && map[i][j] != '#') {
                    if (m[dir].count(i * LEN + j)) { return true; }
                    else { m[dir].insert(i * LEN + j), --j; }
                }
                if (j >= 0) { ++j, --i, dir = N; }
                break;
        }
    }
    return false;
}

int main() {
    char map[LEN][LEN];
    int place, i = 0, j = 0, si, sj;
    while (true) {
        place = getchar();
        if (place == '.' || place == '#')
            map[i][j++] = place;
        else if (place == '\n')
            ++i, j = 0;
        else if (place == '^')
            si = i, sj = j++;
        else
            break;
    }
    
    const int ti = si, tj = sj;

    Dir dir = N;
    while (si >= 0 && si < LEN && sj >= 0 && sj < LEN) {
        switch (dir) {
            case N:
                while (si >= 0 && map[si][sj] != '#') { map[si--][sj] = 'X'; }
                if (si >= 0) { ++si, ++sj, dir = E; }
                break;
            case E:
                while (sj < LEN && map[si][sj] != '#') { map[si][sj++] = 'X'; }
                if (sj < LEN) { --sj, ++si, dir = S; }
                break;
            case S:
                while (si < LEN && map[si][sj] != '#') { map[si++][sj] = 'X'; }
                if (si < LEN) { --si, --sj, dir = W; }
                break;
            case W:
                while (sj >= 0 && map[si][sj] != '#') { map[si][sj--] = 'X'; }
                if (sj >= 0) { ++sj, --si, dir = N; }
                break;
        }
    }

    int ans = 0;
    for (i = 0; i < LEN; ++i) {
        for (j = 0; j < LEN; ++j) {
            if (map[i][j] == 'X' && (i != ti || j != tj)) {
                map[i][j] = '#';
                ans += isCyclePresent(map, ti, tj);
                map[i][j] = '.';
            }
        }
    }

    cout << ans << endl;
}
