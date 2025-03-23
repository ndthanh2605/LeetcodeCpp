
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
    int row, col;
    vector<int> tree;

    SegmentTree() {}
    SegmentTree(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        n = row * col;

        if (n > 0) {
            tree.resize(n * 4);
            buildTree(matrix, 0, n - 1, 0);
        }
    }

    int getValue(vector<vector<int>>& matrix, int idx) {
        int r = idx / col;
        int c = idx % col;
        if (r >= row || c >= col)
            return 0;
        return matrix[r][c];
    }

    void buildTree(vector<vector<int>>& matrix, int left, int right, int idx) {
        if (left == right) {
            tree[idx] = getValue(matrix, left);
            return;
        }
        int mid = (left + right) / 2;
        buildTree(matrix, left, mid, 2 * idx + 1);
        buildTree(matrix, mid + 1, right, 2 * idx + 2);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    int query(int left, int right, int idx, int qleft, int qright) {
        if (qright < left || right < qleft)
            return 0;
        if (qleft <= left && right <= qright)
            return tree[idx];
        int mid = (left + right) / 2;
        int resLeft = query(left, mid, 2 * idx + 1, qleft, qright);
        int resRight = query(mid + 1, right, 2 * idx + 2, qleft, qright);
        cout << " > query " << left << " " << right << " idx " << idx << " : " << (resLeft + resRight) << endl;
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
            update(left, mid, 2 * idx + 1, pos, val);
        }
        else {
            update(mid + 1, right, 2 * idx + 2, pos, val);
        }
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }
};


class NumMatrix {
public:
    SegmentTree *seg;

    NumMatrix(vector<vector<int>>& matrix) {
        seg = new SegmentTree(matrix);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int qleft = row1 * seg->col + col1;
        int qright = row2 * seg->col + col2;
        return seg->query(0, seg->n - 1, 0, qleft, qright);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */


int main()
{
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix sln(matrix);
    cout << sln.sumRegion(2, 1, 4, 3) << endl;

    return 0;
}
