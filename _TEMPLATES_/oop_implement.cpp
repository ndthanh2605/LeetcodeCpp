// implement operators
friend ostream& operator<<(ostream& os, Box& box) {
	os << box.name << " ";
	return os;
}


// get input by line
string line;
while (getline(cin, line)) {
	//
}