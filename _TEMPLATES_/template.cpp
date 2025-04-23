template<class T>
class MyTemplate {
	T element;
public:
	MyTemplate<T>(T arg) {
		element = arg;
	}
	
	T doSomething(T arg) {
		return element + arg;
	}
};


// template specialization
template<>
class MyTemplate<string> {
	string element;
public:
	MyTemplate<string>(string arg) {
		element = arg;
	}
	
	string doSomething(string arg) {
		return element + " concat with " + arg;
	}
};