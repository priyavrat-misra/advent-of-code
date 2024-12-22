#include <iostream>
#include <sstream>
using namespace std;

int dfs(const string& stone, int blinks) {
    if (!blinks)
        return 1;

    int ans = 0, n = stone.size();
    if (n % 2) {
        string next = n == 1 && stone[0] == '0' ? "1" : to_string(stoll(stone) * 2024);
        return dfs(next, blinks - 1);
    } else {
        int i = stone.find_first_not_of('0', n / 2);
        string next = i == string::npos ? "0" : stone.substr(i);
        return dfs(stone.substr(0, n / 2), blinks - 1) + dfs(next, blinks - 1);
    }
}

int main() {
    string stones;
    getline(cin, stones);
    stringstream ss(stones);
    string stone;
    int ans = 0;
    while (ss >> stone)
        ans += dfs(stone, 25);

    cout << ans << endl;
}
