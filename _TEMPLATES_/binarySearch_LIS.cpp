// using binary search

vector<int> sub;		// the length of LIS
for (auto& i : nums) {
	if (sub.empty() || sub[sub.size() - 1] < i) {
		sub.push_back(i);
	}
	else {
		// find 1st item which is >= i
		auto itr = lower_bound(nums.begin(), nums.end(), i);
		
		// overwrite this item
		sub[itr - sub.begin()] = i;
	}
}

return sub.size();