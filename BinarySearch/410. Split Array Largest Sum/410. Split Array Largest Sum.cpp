
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <numeric>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> prefix(n + 1, 0);
        int left = 0;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
            left = max(left, nums[i]);
        }
        if (k == 1)
            return prefix[n];

        for (auto& i : prefix) {
            cout << " " << i;
        }
        cout << endl;

        // number of subarrays whose sum <= 'sum'
        auto buildSubs = [&](int sum) -> int
            {
                int cnt = 1;
                int curSum = 0;
                for (int i = 0; i < n; i++) {
                    if (curSum + nums[i] > sum) {
                        cnt++;
                        curSum = 0;
                    }
                    else {
                        curSum += nums[i];
                    }
                }
                cout << " > check subs of sum " << sum << ":" << cnt << endl;
                return cnt;
            };

        int right = prefix[n];
        int rs = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (buildSubs(mid) <= k) {
                rs = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return rs;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = { 10,5,13,4,8,4,5,11,14,9,16,10,20,8 };
    vector<int> nums = { 7,2,5,10,8 };
    cout << sln.splitArray(nums, 2) << endl;

    return 0;
}
