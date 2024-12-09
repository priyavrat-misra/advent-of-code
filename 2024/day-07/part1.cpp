#include <iostream>
#include <sstream>
#include <vector>

#define LEN 830

using namespace std;

bool calculable(long long res, long long sum, int i, vector<int>& nums) {
    if (sum > res)
        return false;
    else if (i == nums.size())
        return res == sum;
    else
        return calculable(res, sum + nums[i], i + 1, nums) || calculable(res, sum * nums[i], i + 1, nums);
}

int main() {
    long long ans = 0;
    string eq;
    stringstream ss;
    while (getline(cin, eq)) {
        ss.clear();
        ss.str(eq);

        long long res;
        ss >> res;
        ss.ignore(1);

        int num;
        vector<int> nums;
        while (ss >> num) { nums.push_back(num); }

        if (calculable(res, nums[0], 1, nums)) { ans += res; }
    }

    cout << ans << endl;
}
