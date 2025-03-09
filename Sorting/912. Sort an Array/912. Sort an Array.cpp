
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <numeric>
#include <cstdlib>

using namespace std;

class Solution {
public:
    Solution() {
        srand(time(0));
    }

    vector<int> mergeSort(vector<int>& nums, int left, int right) {
        if (left > right)
            return {};
        if (left == right)
            return{ nums[left] };

        int mid = (left + right) / 2;
        vector<int> lefts = mergeSort(nums, left, mid);
        vector<int> rights = mergeSort(nums, mid + 1, right);

        int p1 = 0;
        int p2 = 0;
        vector<int> rs;
        while (p1 < lefts.size() && p2 < rights.size()) {
            if (lefts[p1] < rights[p2]) {
                rs.push_back(lefts[p1++]);
                continue;
            }
            rs.push_back(rights[p2++]);
        }
        while (p1 < lefts.size()) {
            rs.push_back(lefts[p1++]);
        }
        while (p2 < rights.size()) {
            rs.push_back(rights[p2++]);
        }
        return rs;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;

        cout << " > sort from " << low << " to " << high << endl;

        // choose random pivot
        int randIdx = low + rand() % (high - low + 1);
        swap(nums[randIdx], nums[high]);
        int pivot = nums[high];
        cout << "   > random idx " << randIdx << " pivot " << pivot << endl;

        int pivotIdx = low;
        for (int i = low; i < high; i++) {
            if (nums[i] <= pivot) {
                swap(nums[pivotIdx++], nums[i]);
            }
        }
        swap(nums[pivotIdx], nums[high]);
        cout << "   > place " << nums[pivotIdx] << " at idx " << pivotIdx << endl;
        quickSort(nums, low, pivotIdx - 1);
        quickSort(nums, pivotIdx + 1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums;

        //quickSort(nums, 0, nums.size() - 1);
        vector<int> rs = mergeSort(nums, 0, nums.size() - 1);
        return rs;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = { 5,1,1,2,0,0 };
    nums = sln.sortArray(nums);
    for (auto& i : nums) {
        cout << " " << i;
    }
    cout << endl;

    return 0;
}
