vector<int> parent(n);
vector<int> height(n, 1);
int setCnt = n;

for (int i = 0; i < n; i++) {
	parent[i] = i;
}

void Find(int x) {
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void Union(int x, int y) {
	int rootX = find(x);
	int rootY = find(y);
	
	if (rootX == rootY)
		return;
		
	if (height[rootX] > height[rootY]) {
		parent[rootY] = rootX;
	}
	else {
		parent[rootX] = rootY;
		if (height[rootX] == height[rootY])
			height[rootX]++;
	}
	setCnt--;
}