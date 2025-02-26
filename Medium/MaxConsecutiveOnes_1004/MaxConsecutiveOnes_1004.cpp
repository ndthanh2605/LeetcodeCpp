
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int p1 = 0, flipped = 0, maxL = 0;
        for (int p2 = 0; p2 < nums.size(); p2++)
        {
            if (nums[p2] == 0)
                flipped++;

            while (flipped > k)
            {
                if (nums[p1] == 0)
                    flipped--;
                p1++;
            }

            maxL = max(maxL, p2 - p1 + 1);
        }
        return maxL;
    }
};

int main()
{
    Solution sln;
    vector<int> nums({ 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 });
    cout << sln.longestOnes(nums, 3) << endl;

    return 0;
}
