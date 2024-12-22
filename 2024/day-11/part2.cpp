#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

unordered_map<string, unordered_map<int, long long>> dp;

long long dfs(const string& stone, int blinks) {
    if (!blinks)
        return 1;

    if (dp.count(stone) && dp[stone].count(blinks))
        return dp[stone][blinks];

    int ans = 0, n = stone.size();
    if (n % 2) {
        string next = n == 1 && stone[0] == '0' ? "1" : to_string(stoll(stone) * 2024);
        return dp[stone][blinks] = dfs(next, blinks - 1);
    } else {
        int i = stone.find_first_not_of('0', n / 2);
        string next = i == string::npos ? "0" : stone.substr(i);
        return dp[stone][blinks] = dfs(stone.substr(0, n / 2), blinks - 1) + dfs(next, blinks - 1);
    }
}

int main() {
    string stones;
    getline(cin, stones);
    stringstream ss(stones);
    string stone;
    long long ans = 0;
    while (ss >> stone)
        ans += dfs(stone, 75);

    cout << ans << endl;
}
