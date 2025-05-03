#ifndef WIDGET_H
#define WIDGET_H

#include <iostream>

using namespace std;

class Widget {
public:
	Widget(const string& name);
	~Widget();

	// Rule of 5
	Widget(const Widget&) = delete;				// copy constructor
	Widget& operator=(const Widget&) = delete;	// copy assignment

	Widget(Widget&&) noexcept;					// move constructor
	Widget& operator=(Widget&&) noexcept;		// move assignment

	void doSth();
	string getName();

private:
	class WidgetImpl;

	unique_ptr<WidgetImpl> mPimpl;
};

#endif // WIDGET_H