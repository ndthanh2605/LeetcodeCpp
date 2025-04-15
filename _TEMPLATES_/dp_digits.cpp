// dp top down
auto dp = [&](int pos, int tight, int state, string& num, int n) -> int
{
	if (pos == n)
		return (state == 0)? 1 : 0;
	
	int rs = 0;
	int limit = tight? num[pos] - '0' : 9;
	for (int i = 0; i <= limit; i++) {
		int newTight = tight && (i == limit);
		int newState = state;
		if (pos < n/2) {
			newState += i;
		}
		else {
			newState -= i;
		}
		rs += dp(pos + 1, newTight, newState, num, n);
	}
	return rs;
};


// memoization
vector<vector<vector<int>>> dp;		// pos (n -> 0) , tight (0/1) & state of current pos (e.g. sum, diff...)

