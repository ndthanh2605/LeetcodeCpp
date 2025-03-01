
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return { -1 };
        }

        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }

        stack<int> st;
        vector<int> rs(n, -1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            int cur = nums[i];
            while (!st.empty() && cur >= st.top()) {
                //cout << " > pop " << st.top() << endl;
                st.pop();
            }
            if (!st.empty() && i < n) {
                //cout << "   > set rs " << i << ": " << st.top() << endl;
                rs[i] = st.top();
            }
            //cout << " > push " << cur << endl;
            st.push(cur);
        }

        return rs;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = { 1,2,3,4,3 };
    vector<int> nums = { 1,2,1 };
    vector<int> rs = sln.nextGreaterElements(nums);
    for (auto& i : rs)
    {
        cout << " " << i;
    }
    cout << endl;

    return 0;
}
