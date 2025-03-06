
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        // find 1st position
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int rs = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                rs = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return rs;
    }

    int upperBound(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int rs = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                rs = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return rs;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return { -1, -1 };

        int n = nums.size();
        vector<int> rs(2);
        rs[0] = lowerBound(nums, target);
        if (rs[0] >= n || nums[rs[0]] != target) {
            // not found
            return { -1, -1 };
        }

        rs[1] = upperBound(nums, target) - 1;

        return rs;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = { 5,7,7,8,8,10 };
    sln.searchRange(nums, 8);

    return 0;
}
