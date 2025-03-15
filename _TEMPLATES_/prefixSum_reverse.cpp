// find sum of queries
// query: [l, r, w] -> increase 'w' for all items in range [l, r]

vector<int> tmp(n + 1);
for (auto& q : queries) {
	int l = q[0], r = q[1], w = q[2];
	// add item at 'l' and subtract item at ('r' + 1)
	tmp[l] += w;
	tmp[r + 1] -= w;
}

// build sum (~prefix sum, but in reverse order) - last sum will always be 0
vector<int> sum(n);
sum[0] = tmp[0];
for (int i = 1; i < n; i++) {
	sum[i] = sum[i - 1] + tmp[i];
}


// e.g. queries [1, 2, 1], [0, 2, 2], [0, 0, 1]
// tmp [0, 0, 0, 0] -> [0, 1, 0, -1] -> [2, 1, 0, -3] -> [3, 0, 0, -3]
// sum [3, 3, 3]