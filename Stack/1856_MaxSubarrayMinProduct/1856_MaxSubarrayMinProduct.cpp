
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        // prefix
        int n = nums.size();
        if (n == 1)
            return nums[0] * nums[0];

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        for (auto& i : prefix)
        {
            cout << " " << i;
        }
        cout << endl;

        // find 1st smaller item on left
        stack<int> stLeft;
        vector<int> smL(n, -1);
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            while (!stLeft.empty() && cur <= nums[stLeft.top()]) {
                stLeft.pop();
            }
            if (!stLeft.empty()) {
                smL[i] = stLeft.top();
            }
            stLeft.push(i);
        }
        for (auto& i : smL)
        {
            cout << " " << i;
        }
        cout << endl;

        // find 1st smaller item on right
        stack<int> stRight;
        vector<int> smR(n, n);
        for (int i = n - 1; i >= 0; i--) {
            int cur = nums[i];
            while (!stRight.empty() && cur <= nums[stRight.top()]) {
                stRight.pop();
            }
            if (!stRight.empty()) {
                smR[i] = stRight.top();
            }
            stRight.push(i);
        }
        for (auto& i : smR)
        {
            cout << " " << i;
        }
        cout << endl;

        long tmpMax = 0;
        for (int i = 0; i < n; i++) {
            // range in which number i is smaller
            int l = smL[i] + 1;
            int r = smR[i];
            long sum = prefix[r] - prefix[l];
            cout << " > product at " << i << ": " << sum << " x " << nums[i] << " -> " << (nums[i] * sum) << endl;
            tmpMax = max(tmpMax, nums[i] * sum);
        }
        int rs = tmpMax % (int)(1e9 + 7);
        
        return rs;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = { 2,5,4,2,4,5,3,1,2,4 };
    //vector<int> nums = { 1,2,3,2 };
    cout << sln.maxSumMinProduct(nums) << endl;

    return 0;
}
