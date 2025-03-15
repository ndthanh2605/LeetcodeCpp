// 1358. Number of Substrings Containing All Three Characters

int numberOfSubstrings(string s) {
	int n = s.length();
	if (n < 3)
		return 0;

	int rs = 0;
	unordered_map<char, int> freq;
	int l = 0;
	for (int r = 0; r < n; r++) {
		char c = s[r];
		freq[c]++;

		while (freq.size() == 3) {
			rs += n - r;

			// move left
			char d = s[l];
			freq[d]--;
			if (freq[d] == 0)
				freq.erase(d);
			l++;
		}
	}
	return rs;
}