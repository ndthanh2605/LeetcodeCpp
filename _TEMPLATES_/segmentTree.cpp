class SegmentTree {
public:
    int n;
    vector<int> tree;
    
    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        if (n > 0) {
			tree = vector<int>(4 * n);
            buildTree(nums, 0, 0, n - 1);
        };
    }

    void buildTree(const vector<int>& nums, int left, int right, int idx) {
        if (left == right) {
			tree[idx] = nums[idx];
			return;
		}
		int mid = (left + right) / 2;
		buildTree(nums, left, mid, 2 * idx + 1);
		buildTree(nums, mid + 1, right, 2 * idx + 2);
		tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }
	
	void query(int left, int right, int idx, int qleft, int qright) {
		if (left > qright || qright < left) {
			return;
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
			update(left, mid, 2 * idx + 1, pos, val);
		} else {
			update(mid + 1, right, 2 * idx + 2, pos, val);
		}
		tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
	}
	
};