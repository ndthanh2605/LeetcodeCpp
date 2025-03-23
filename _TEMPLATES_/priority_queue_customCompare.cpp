class Compare {
public:
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
		if (a.first < b.first)
			return true;
		if (a.first == b.first && a.second.compare(b.second))
			return true;
		return false;
	}
};