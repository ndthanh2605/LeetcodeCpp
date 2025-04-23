string ltrim(const string& str) {
	auto first_non_space = find_if(str.begin(), str.end(),
		[](unsigned char) { return !isspace(c); });
	return string(first_non_space, str.end());
}

string rtrim(const string& str) {
	auto last_non_space = find_if(str.rbegin(), str.rend(),
		[](unsigned char c) { return isspace(c); }).base();
	return string(str.begin(), last_non_space);
}

vector<string> split(const string& str) {
	vector<string> tokens;
	istringstream iss(str);
	
	string tmp;
	while (iss >> tmp) {
		tokens.push_back(tmp);
	}
	
	return tokens;
}


// find substring
int pos = str.find(sub);
if (pos == string::npos)
	return -1;