
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());     // must sort before using '2 pointer' method

        set<vector<int>> rs;
        for (int i = 0; i < nums.size(); i++)
        {
            // fix the value at idx 'i' and use 2 pointers to find the pair in the rest of list
            int target = -nums[i];
            int p1 = i + 1, p2 = nums.size() - 1;
            while (p1 < p2)
            {
                if (nums[p1] + nums[p2] == target) {
                    rs.insert({ -target, nums[p1], nums[p2] });
                    p1++; p2--;
                }
                else if (nums[p1] + nums[p2] < target) {
                    p1++;
                }
                else {
                    p2--;
                }
            }
        }
        return vector<vector<int>>(rs.begin(), rs.end());
    }

};

int main()
{
    Solution sln;
    cout << sln << endl;

    return 0;
}
