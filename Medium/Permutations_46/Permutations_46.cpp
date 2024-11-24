// Permutations_46.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> rs;
        do
        {
            rs.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return rs;
    }
};

int main()
{
    vector<int> nums = { 1, 1, 2 };
    Solution sln;
    cout << sln.permute(nums).size() << endl;

    return 0;
}
