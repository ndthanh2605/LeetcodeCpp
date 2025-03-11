
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
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        auto atLeastDifferentNumbers = [&](int m) -> int
            {
                int rs = 0;
                unordered_map<int, int> freq;
                int l = 0;
                for (int r = 0; r < n; r++) {
                    freq[nums[r]]++;

                    while (freq.size() >= m) {
                        // all sub arrays ending from r to end of nums are valid
                        rs += n - r;

                        // move left
                        freq[nums[l]]--;
                        if (freq[nums[l]] == 0)
                            freq.erase(nums[l]);
                        l++;
                    }
                }

                return rs;
            };

        return atLeastDifferentNumbers(k) - atLeastDifferentNumbers(k + 1);
    }
};

int main()
{
    Solution sln;
    vector<int> nums = { 1,2,1,2,3 };
    cout << sln.subarraysWithKDistinct(nums, 2) << endl;

    return 0;
}
