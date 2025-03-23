// expand left & right from center idx in string to check palindrome
auto checkPalind = [&](int c1, int c2) -> vector<int>
{
	while (c1 >= 0 && c2 < n) {
		if (s[c1] != s[c2])
			break;
		c1--; c2++;
	}
	return { c1 + 1, c2 - 1 };
};

