// implement operators
friend ostream& operator<<(ostream& os, Box& box) {
	os << box.name << " ";
	return os;
}

