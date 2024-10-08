// Easy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include "Solution.h"

using namespace std;

string toString(const vector<int>& input);

int main()
{
    Solution sln;
    vector<int> input = vector<int>{ 1, 2, 3, 4 };
    vector<int> rs = sln.runningSum(input);

    //cout << toString(rs) << endl;

    ListNode* tail = new ListNode(1);
    ListNode* head = new ListNode(2, tail);
    head = new ListNode(2, head);
    head = new ListNode(1, head);
    cout << "done init linked list" << endl;

    cout << sln.isPalindrome(head) << endl;

    system("pause");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

string toString(const vector<int>& input)
{
    if (input.empty()) {
        return "";
    }
    stringstream ss;
    copy(input.begin(), input.end(), ostream_iterator<int>(ss, " "));
    string s = ss.str();
    s = s.substr(0, s.length() - 1);
    return s;
}
