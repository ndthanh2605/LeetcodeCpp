
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int rs = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if ((mid == left || nums[mid] < nums[mid - 1]) && (mid == right || nums[mid] < nums[mid + 1]))
                return nums[mid];

            if (nums[mid] < nums[right]) {
                // min is somewhere on the left
                rs = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return nums[rs];
    }
};

int main()
{
    Solution sln;
    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    cout << sln.findMin(nums) << endl;

    return 0;
}
