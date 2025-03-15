// build freq of elements
int mx = *max_element(nums.begin(), nums.end());

vector<int> freq(mx + 1);
for (auto& i : nums) {
	freq[i]++;
}

// cummulative
for (int i = 1; i <= n; i++) {
	freq[i] += freq[i - 1];
}

// build output result
vector<int> rs(n);
for (int i = n - 1; i >= 0; i--) {
	int cur = nums[i];
	rs[freq[cur] - 1] = cur;
	freq[cur]--;
}
