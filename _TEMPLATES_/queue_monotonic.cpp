// find the maximum value in each sliding window of size k

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result;
    deque<int> dq;  // store indices

    for (int i = 0; i < nums.size(); ++i) {
        // Remove indices that are out of the current window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove indices whose corresponding values are less than nums[i]
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);

        // Append current max to result
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}