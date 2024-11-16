// PartitionEqualSubsetSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

map<pair<int, int>, bool> cached;

bool canSum(vector<int>& nums, int sum, int startIdx) {
    pair<int, int> key = make_pair(startIdx, sum);
    //cout << "  >> canSum " << sum << ", start " << startIdx << endl;
    if (cached.find(key) != cached.end())
        return cached[key];

    auto itr = find(nums.begin() + startIdx, nums.end(), sum);
    if (itr != nums.end()) {
        cached[key] = true;
        return true;
    }

    if (startIdx == nums.size() - 1) {      // the last item, but it's been checked not equal to 'sum'
        cached[key] = false;
        return false;
    }
    cached[key] = canSum(nums, sum, startIdx + 1) || canSum(nums, sum - nums[startIdx], startIdx + 1);
    return cached[key];
}

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
        return false;

    sum = sum / 2;
    int max = *max_element(nums.begin(), nums.end());
    if (max > sum)
        return false;

    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = sum; j >= nums[i]; j--)
        {
            if (dp[j - nums[i]] == true)
                dp[j] = true;
        }
    }
    return dp[sum];
}

bool canPartition_recursion(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
        return false;

    sum = sum / 2;
    int max = *max_element(nums.begin(), nums.end());
    if (max > sum)
        return false;

    cached.clear();
    //cout << " > check sum " << sum << endl;
    return canSum(nums, sum, 0);
}

int main()
{
    vector<int> nums({ 48,23,81,49,89,4,29,58,61,91,26,79,81,48,64,1,81,2,36,82,16,97,23,56,50,48,74,50,74,81,10,5,76,66,77,16,19,57,88,89,98,31,16,99,58,84,63,100,79,66,15,62,68,54,29,74,53,83,5,34,42,28,84,62,64,90,29,56,14,69,9,2,45,1,53,5,51,9,42,97,33,42,55,25,96,7,86,79,1,42,94,43,2,16,51,21,40,19,12 });
    cout << canPartition(nums) << endl;
}
