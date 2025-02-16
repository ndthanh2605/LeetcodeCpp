
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (auto& i : nums)
        {
            q.push(i);
        }
        for (int i = 0; i < k-1; i++)
        {
            q.pop();
        }
        return q.top();
    }

};

int main()
{
    Solution sln;
    vector<int> nums = { 3,2,1,5,6,4 };
    cout << sln.findKthLargest(nums, 2) << endl;

    return 0;
}
