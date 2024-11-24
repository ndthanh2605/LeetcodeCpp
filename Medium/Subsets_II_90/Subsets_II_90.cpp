// Subsets_II_90.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    set<vector<int>> rs;
    vector<int> tmp;

    // try select or remove item at idx of nums
    void Try(vector<int>& nums, int idx) {
        for (int i = 0; i < 2; i++)
        {
            if (i == 0) {
                tmp.push_back(nums[idx]);
            }
            if (idx == nums.size() - 1) {
                rs.insert(tmp);
            }
            else {
                Try(nums, idx + 1);
            }

            // backtrack
            if (i == 0) {
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        Try(nums, 0);

        return vector<vector<int>>(rs.begin(), rs.end());
    }
};

int main()
{
    vector<int> nums = { 1, 2, 2 };
    Solution sln;
    cout << sln.subsetsWithDup(nums).size() << endl;

    return 0;
}
