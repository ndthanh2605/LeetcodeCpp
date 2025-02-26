
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProducts(nums.size());
        vector<int> rightProducts(nums.size());

        int tmp = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            tmp *= nums[i];
            leftProducts[i] = tmp;
        }

        tmp = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            tmp *= nums[i];
            rightProducts[i] = tmp;
        }

        vector<int> rs(nums.size());
        rs[0] = rightProducts[1];
        rs[nums.size() - 1] = leftProducts[nums.size() - 2];
        for (int i = 1; i < nums.size() - 1; i++)
        {
            rs[i] = leftProducts[i - 1] * rightProducts[i + 1];
        }
        return rs;
    }
};

int main()
{
    Solution sln;

    vector<int> nums = { -1, 1, 0, -3, 3 };
    vector<int> rs = sln.productExceptSelf(nums);
    for (auto& i : rs)
    {
        cout << " " << i;
    }
    cout << endl;
    //cout << sln << endl;

    return 0;
}
