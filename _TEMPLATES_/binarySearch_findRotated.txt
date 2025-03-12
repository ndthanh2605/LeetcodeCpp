int left = 0;
int right = n - 1;
while (left < right) {
	int mid = (left + right) / 2;
	int cur = nums[mid];
	if (cur == target)
		return mid;

	if (cur < nums[right]) {
		// mid to right is increasing -> min is somewhere on left
		right = mid;
	}
	else {
		left = mid + 1;
	}
}