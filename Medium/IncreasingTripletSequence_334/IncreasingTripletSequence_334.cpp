
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    bool increasingTriplet(vector<int>& nums) {
        // binary search
        vector<int> lis;

        for (auto& i : nums)
        {
            auto itr = lower_bound(lis.begin(), lis.end(), i);  // 1st item which is greater than i
            if (itr == lis.end()) {
                lis.push_back(i);
                if (lis.size() == 3)
                    return true;
            }
            else {
                *itr = i;
            }
        }
        return false;
    }

    bool increasingTriplet_(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        
        int min1 = INT_MAX, min2 = INT_MAX;
        for (auto& i : nums)
        {
            if (i <= min1)
                min1 = i;       // found 1st num
            else if (i <= min2)
                min2 = i;       // found 2nd num
            else
                return true;    // found 3rd item
        }
        return false;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = { 1,2,3,4,5 };
    cout << sln.increasingTriplet(nums) << endl;

    return 0;
}
