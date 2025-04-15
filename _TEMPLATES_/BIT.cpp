vector<int> BIT(n + 1, 0);

void update(int i, int delta) {
	i++;
	for (; i <= n; i += i & (-1)) {
		BIT[i] += delta;
	}
}

int query(int i) {
	i++;
	int sum = 0;
	for (; i > 0; i -= i & (-i)) {
		sum += BIT[i];
	}
	return sum;
}