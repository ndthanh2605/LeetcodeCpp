// SearchInsertPos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsertWithin(vector<int>& nums, int target, int start, int end) {
        cout << "> search " << target << " in range (" << start << ", " << end << ")" << endl;
        int l = end - start + 1;
        if (l == 1) {
            return (nums[start] < target) ? start + 1 : start;
        }

        int sep = (start + end) / 2;
        int mid = nums[sep];
        if (mid == target) {
            return sep;
        }
        if (mid < target) {
            return searchInsertWithin(nums, target, sep+1, end);
        }
        return searchInsertWithin(nums, target, start, sep);
    }

    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
        int l = nums.size();
        if (l == 1) {
            return (nums[0] < target) ? 1 : 0;
        }
        return searchInsertWithin(nums, target, 0, l-1);
    }
};

int main()
{
    vector<int> nums = vector<int>{ 1,3,5,6 };
    Solution sln;
    cout << sln.searchInsert(nums, 7) << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
