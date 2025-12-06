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

    long long ans = 0;
    for (auto& range : merged)
        ans += range.second - range.first + 1;

    cout << ans << endl;
}
