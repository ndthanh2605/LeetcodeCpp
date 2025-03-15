// find previous greater
vector<int> rs(n, -1);
stack<int> st;

for (int i = 0; i < n; i++) {
	int cur = nums[i];
	while (!st.empty() && cur >= st.top()) {
		st.pop();
	}
	if (!st.empty()) {
		rs[i] = st.top();
	}
	st.push(cur);
}


// find following smaller
vector<int> rs(n, n);
for (int i = n - 1; i >= 0; i--) {
	int cur = nums[i];
	while (!st.empty() && cur <= st.top()) {
		st.pop();
	}
	if (!st.empty()) {
		rs[i] = st.top():
	}
	st.push(cur);
}