
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k)
            return false;
        
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = total / k;
        if (nums[0] > sum)
            return false;

        vector<bool> visited(n, false);
        // try build 'idx' subset
        // try through every elements, select or skip for the subset
        vector<int> curSum(k, 0);
        function<bool(int,int)> Try = [&](int idx, int i) -> bool
            {
                if (idx == k)
                    return count(visited.begin(), visited.end(), true) == n;

                for (int j = i; j < n; j++) {
                    if (visited[j])
                        continue;
                    if (curSum[idx] + nums[j] > sum)
                        continue;

                    visited[j] = true;
                    curSum[idx] += nums[j];
                    
                    if (curSum[idx] == sum) {
                        if (Try(idx + 1, 0))
                            return true;
                    }
                    else {
                        if (Try(idx, i + 1))
                            return true;
                    }

                    visited[j] = false;
                    curSum[idx] -= nums[j];

                    // optimize
                    if (curSum[idx] == 0)
                        break;
                }
                return false;
            };

        return Try(0, 0);
    }
};

int main()
{
    Solution sln;
    vector<int> nums = { 2,2,2,2,3,4,5 };
    cout << sln.canPartitionKSubsets(nums, 4) << endl;

    return 0;
}
