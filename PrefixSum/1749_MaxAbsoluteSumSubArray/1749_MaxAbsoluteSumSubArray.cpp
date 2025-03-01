
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int rs = -INT_MAX;

        int curSum = 0;
        int maxPrefix = 0;
        int minPrefix = 0;
        
        int tmp1, tmp2;
        for (auto& i : nums) {
            curSum += i;
            maxPrefix = max(maxPrefix, curSum);
            minPrefix = min(minPrefix, curSum);
            tmp1 = abs(curSum - maxPrefix);
            tmp2 = abs(curSum - minPrefix);
            rs = max(rs, max(tmp1, tmp2));
        }

        return rs;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = { 1,-3,2,3,-4 };
    cout << sln.maxAbsoluteSum(nums) << endl;

    return 0;
}
