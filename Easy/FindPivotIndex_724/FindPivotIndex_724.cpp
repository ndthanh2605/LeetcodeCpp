
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum - nums[9])
            return 0;
        
        int tmp = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            tmp += nums[i];
            if (tmp * 2 == sum - nums[i + 1]) {
                return i + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sln;
    vector<int> nums({ 2,1,-1 });
    cout << sln.pivotIndex(nums) << endl;

    return 0;
}
