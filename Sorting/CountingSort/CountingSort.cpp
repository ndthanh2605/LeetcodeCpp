
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
    vector<int> countingSort(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return nums;

        // build freqs
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> cnt(mx + 1);
        for (auto& i : nums) {
            cnt[i]++;
        }

        // cummulative
        for (int i = 1; i <= mx; i++) {
            cnt[i] += cnt[i - 1];
        }

        // build output
        vector<int> rs(n);
        for (int i = n - 1; i >= 0; i--) {
            int cur = nums[i];
            rs[cnt[cur] - 1] = cur;
            cnt[cur]--;
        }
        return rs;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = { 2,0,2,1,1,0 };
    nums = sln.countingSort(nums);
    for (auto& i : nums) {
        cout << " " << i;
    }
    cout << endl;

    return 0;
}
