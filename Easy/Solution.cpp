#include "Solution.h"

vector<int> Solution::runningSum(vector<int>& nums)
{
    vector<int> rs;
    int l = nums.size();
    if (l < 1 || l > 1000)
        return rs;
    rs.push_back(nums[0]);
    for (int i = 1; i < l; i++) {
        int n = rs[i - 1] + nums[i];
        rs.push_back(n);
    }
    return rs;
}
