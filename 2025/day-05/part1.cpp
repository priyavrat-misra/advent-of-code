#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    vector<pair<long long, long long>> ranges;
    while (getline(cin, s))
        if (s.empty())
            break;
        else
            ranges.emplace_back(stoll(s), stoll(s.substr(s.find('-') + 1)));

    sort(ranges.begin(), ranges.end());
    int n = ranges.size();
    vector<pair<long long, long long>> merged;
    merged.push_back(ranges.front());
    for (int i = 1; i < n; ++i)
        if (ranges[i].first <= merged.back().second)
            merged.back().second = max(merged.back().second, ranges[i].second);
        else
            merged.push_back(ranges[i]);

    int ans = 0;
    long long id;
    while (cin >> id) {
        auto it = upper_bound(merged.begin(), merged.end(), id, [](long long id, const auto& range) { return range.first > id; });
        ans += it != merged.begin() && id >= (it - 1) -> first && id <= (it - 1) -> second;
    }
    cout << ans << endl;
}
