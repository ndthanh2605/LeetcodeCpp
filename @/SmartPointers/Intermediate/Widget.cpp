#include "Widget.h"

class Widget::WidgetImpl {
private:
	string mName;
	int mCnt = 0;

public:
	WidgetImpl(const string& name) : mName(name) {
		cout << "[" << mName << "] WidgetImpl constructed" << endl;
	}

	~WidgetImpl() {
		cout << "[" << mName << "] WidgetImpl DESTROYED!!!" << endl;
	}

	void doSthImpl() {
		mCnt++;
		cout << "[" << mName << "] doSthImpl called, cnt " << mCnt << endl;
	}

	string getNameImpl() {
		return mName;
	}

};

Widget::Widget(const string& name)
	: mPimpl(make_unique<WidgetImpl>(name))
{
	cout << "Widget [" << mPimpl->getNameImpl() << "] constructed" << endl;
}

Widget::~Widget() {
	cout << "Widget [" << mPimpl->getNameImpl() << "] destroyed!!!" << endl;
}

Widget::Widget(Widget&&) noexcept = default;
Widget& Widget::operator=(Widget&&) noexcept = default;

void Widget::doSth() {
	if (mPimpl)
		mPimpl->doSthImpl();
	else
		cout << "[ERR] Impl is moved from widget" << endl;
}

string Widget::getName() {
	if (mPimpl)
		return mPimpl->getNameImpl();
	return "[ERR] Impl is moved from widget";
}