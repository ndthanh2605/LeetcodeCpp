
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int curSum = nums[0];
        int minPrefix = 0;
        int rs = max(-INT_MAX, curSum);

        for (int i = 1; i < nums.size(); i++) {
            minPrefix = min(minPrefix, curSum);
            curSum += nums[i];
            rs = max(rs, curSum - minPrefix);
            cout << " > sum " << curSum << " minPre " << minPrefix << " rs " << rs << endl;
        }

        return rs;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = { 5,4,-1,7,8 };
    cout << sln.maxSubArray(nums) << endl;

    return 0;
}
