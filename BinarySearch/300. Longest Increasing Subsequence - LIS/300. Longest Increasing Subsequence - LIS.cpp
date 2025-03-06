
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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;

        vector<int> sub;        // to check length of LIS
        for (auto& i : nums) {
            if (sub.empty() || sub[sub.size() - 1] < i) {
                sub.push_back(i);
            }
            else {
                // find a place in 'sub' & overwrite value
                // the 1st item which is >= i
                auto itr = lower_bound(sub.begin(), sub.end(), i);
                sub[itr - sub.begin()] = i;
            }
        }

        return sub.size();
    }
};

int main()
{
    Solution sln;
    vector<int> nums = { 7,7,7 };
    cout << sln.lengthOfLIS(nums) << endl;

    return 0;
}
