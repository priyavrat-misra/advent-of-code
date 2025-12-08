#include <execution>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    int num;
    vector<int> nums;
    while (cin >> num)
        nums.push_back(num);

    cin.clear();
    char op;
    vector<char> ops;
    while (cin >> op)
        ops.push_back(op);

    int n = ops.size(), m = nums.size() / n;
    vector<vector<int>> cols(n);
    for (auto& col : cols)
        col.reserve(m);

    int c = 0;
    for (int num : nums) {
        cols[c++].push_back(num);
        if (c == n)
            c = 0;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i)
        if (ops[i] == '+')
            ans += reduce(execution::unseq, cols[i].begin(), cols[i].end(), 0ll);
        else
            ans += reduce(execution::unseq, cols[i].begin(), cols[i].end(), 1ll, std::multiplies<long long>());

    cout << ans << endl;
}
