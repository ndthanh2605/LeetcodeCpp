#pragma once

#include <iostream>

using namespace std;


void factory();

class Widget {
public:
	virtual ~Widget() {
		cout << "Base destroyed!!!" << endl;
	}
	virtual void draw() const = 0;
};

class WidgetA : public Widget {
public:
	WidgetA() = default;
	~WidgetA() {
		cout << "Derived A destroyed!!!" << endl;
	}

	void draw() const override {
		cout << "Derived A draw" << endl;
	}
};

class WidgetB : public Widget {
public:
	WidgetB() = default;
	~WidgetB() {
		cout << "Derived B destroyed!!!" << endl;
	}

	void draw() const override {
		cout << "Derived B draw" << endl;
	}
};


class WidgetFactory {
public:
	static unique_ptr<Widget> createWidget(const string& type) {
		if (type == "A")
			return make_unique<WidgetA>();

		if (type == "B")
			return make_unique<WidgetB>();

		throw runtime_error("Unknown widget type");
	}
};


void factory()
{
	unique_ptr<Widget> w1, w2, wX;
	try {
		w1 = WidgetFactory::createWidget("A");
		w1->draw();
		w2 = WidgetFactory::createWidget("B");
		w2->draw();
		wX = WidgetFactory::createWidget("C");
	}
	catch (const runtime_error& e) {
		cerr << "Factory ERROR: " << e.what() << endl;
	}

	cout << " > leaving scope..." << endl;
}
