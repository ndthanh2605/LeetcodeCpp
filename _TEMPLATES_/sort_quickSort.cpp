// NOTE : must call srand(time(0)) in class constructor

void quickSort(vector<int>& nums, int left, int right) {
	if (left >= right)
		return;
	
	int randIdx = left + rand() % (right - left + 1);
	swap(nums[randIdx], nums[right]);
	
	int pivot = nums[right];
	int pivotIdx = 0;
	
	for (int i = left; i < right; i++) {
		if (nums[i] < pivot) {
			swap(nums[pivotIdx++], nums[i]);
		}
	}
	swap(nums[pivotIdx], nums[right]);
	
	quickSort(nums, left, pivotIdx - 1);
	quickSort(nums, pivotIdx + 1, right);
}