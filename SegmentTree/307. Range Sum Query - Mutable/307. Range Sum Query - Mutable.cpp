
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <numeric>

using namespace std;
class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree() : n(0) {}

    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        // n must > 0
        tree = vector<int>(4 * n);

        buildTree(nums, 0, n - 1, 0);
    }

    void buildTree(const vector<int>& nums, int left, int right, int idx) {
        if (left == right) {
            // leaf node
            tree[idx] = nums[left];
            return;
        }

        int mid = (left + right) / 2;
        buildTree(nums, left, mid, 2 * idx + 1);
        buildTree(nums, mid + 1, right, 2 * idx + 2);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    int query(int left, int right, int idx, int qleft, int qright) {
        if (qleft > right || left > qright) {
            // out of range
            return 0;
        }

        if (qleft <= left && right <= qright) {
            return tree[idx];
        }

        int mid = (left + right) / 2;
        int resLeft = query(left, mid, 2 * idx + 1, qleft, qright);
        int resRight = query(mid + 1, right, 2 * idx + 2, qleft, qright);
        return resLeft + resRight;
    }

    void update(int left, int right, int idx, int pos, int val) {
        if (pos < left || pos > right)
            return;

        if (left == right) {
            tree[idx] = val;
            return;
        }

        int mid = (left + right) / 2;
        if (pos <= mid) {
            // update on left
            update(left, mid, 2 * idx + 1, pos, val);
        }
        else {
            update(mid + 1, right, 2 * idx + 2, pos, val);
        }
        // update parent node
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }
};

class NumArray {
public:
    SegmentTree stree;

    NumArray(vector<int>& nums) {
        stree = SegmentTree(nums);
    }

    void update(int index, int val) {
        stree.update(0, stree.n - 1, 0, index, val);
    }

    int sumRange(int left, int right) {
        return stree.query(0, stree.n - 1, 0, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main()
{
    Solution sln;
    //cout << sln << endl;

    return 0;
}
