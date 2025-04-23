int kadane(const vector<int>& nums) {
	if (nums.empty())
		return 0;
	
	int n = nums.size();
	int mx = nums[0];
	int curSum = nums[0];
	for (int i = 1; i < n; i++) {
		curSum = max(nums[i], curSum + nums[i]);	// choose if we should continue or re-start at i
		mx = max(mx, curSum);
	}
	return mx;
}