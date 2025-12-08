#include <iostream>
#include <vector>
using namespace std;

int main() {
    string line;
    vector<string> grid;
    while (getline(cin, line))
        grid.push_back(move(line));

    for (auto& row : grid)
        row.append(" #");

    long long ans = 0;
    int m = grid.size(), n = grid.back().size();
    for (int i = 1, j = 0; i < n; ++i) {
        if (grid[m - 1][i] != ' ') {
            if (grid[m - 1][j] == '+') {
                long long col = 0;
                for (; j < i - 1; ++j) {
                    int val = 0;
                    for (int k = 0; k < m - 1; ++k)
                        if (grid[k][j] != ' ')
                            val = val * 10 + (grid[k][j] - '0');
                    col += val;
                }
                ans += col;
            } else {
                long long col = 1;
                for (; j < i - 1; ++j) {
                    int val = 0;
                    for (int k = 0; k < m - 1; ++k)
                        if (grid[k][j] != ' ')
                            val = val * 10 + (grid[k][j] - '0');
                    col *= val;
                }
                ans += col;
            }
            ++j;
        }
    }
    cout << ans << endl;
}
