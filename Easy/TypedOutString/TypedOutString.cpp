// TypedOutString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkStringTypedOutEmpty(string str, int p = -1) {
        if (p < 0)
            p = str.length() - 1;
        int hashCount = 0;
        while (p >= 0)
        {
            if (str[p] == '#') {
                hashCount++;
                p--;
                continue;
            }
            if (hashCount > 0) {
                hashCount--;
                p--;
                continue;
            }
            return false;
        }
        return true;
    }

    bool backspaceCompare(string s, string t) {
        if (s.empty() && t.empty())
            return true;

        int p1 = s.length() - 1;
        int p2 = t.length() - 1;
        
        if (s.empty() || t.empty()) {
            if (!t.empty()) {
                return checkStringTypedOutEmpty(t);
            }
            else {
                return checkStringTypedOutEmpty(s);
            }
        }

        char c1, c2;
        int hashs01 = 0, hashs02 = 0;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 < 0) {
                return checkStringTypedOutEmpty(t, p2);
            }
            if (p2 < 0) {
                return checkStringTypedOutEmpty(s, p1);
            }
            c1 = s[p1];
            c2 = t[p2];
            
            // move p1
            if (c1 == '#') {
                hashs01++;
                p1--;
                continue;
            }
            if (hashs01 > 0) {
                hashs01--;
                p1--;
                continue;
            }

            // move p2
            if (c2 == '#') {
                hashs02++;
                p2--;
                continue;
            }
            if (hashs02 > 0) {
                hashs02--;
                p2--;
                continue;
            }
            if (c1 != c2) {
                return false;
            }
            p1--;
            p2--;
        }

        return true;
    }
};

int main()
{
    Solution sln;
    //string s = "ab#c", t = "ad#c";
    //string s = "ab##", t = "c#d#";
    string s = "a#c", t = "b";
    cout << sln.backspaceCompare(s, t) << endl;
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
