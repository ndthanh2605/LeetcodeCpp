// ShortestSubarrayWithSumAtLeastK_862.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minLength = -1;

    int shortestSubarray(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum >= k) {
                if (i == 0)
                    return 1;
                minLength = i + 1;
                break;
            }
        }
        if (sum < k)
            return -1;

        // sliding windows
        int i = 0;
        sum -= nums[minLength - 1];
        for (int j = minLength - 1; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum >= k + nums[i])
            {
                sum -= nums[i];
                i++;
            }
            int l = j - i + 1;
            if (l < minLength)
                minLength = l;
        }
        return minLength;
    }
};
int main()
{
    vector<int> nums = { 84,-37,32,40,95 };
    Solution sln;
    cout << sln.shortestSubarray(nums, 167) << endl;

    return 0;
}
