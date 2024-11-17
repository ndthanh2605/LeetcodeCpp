// LetterCombinations_17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string digits;
    unordered_map<char, string> letters;
    vector<string> combinations;

    void initLetters() {
        letters['2'] = "abc";
        letters['3'] = "def";
        letters['4'] = "ghi";
        letters['5'] = "jkl";
        letters['6'] = "mno";
        letters['7'] = "pqrs";
        letters['8'] = "tuv";
        letters['9'] = "wxyz";
    }

    void Try(const string& str, int idx) {
        char c = digits[idx];
        for (auto& ch : letters[c])
        {
            string str2 = str + ch;
            if (idx == digits.length() - 1) {
                // end case
                combinations.push_back(str2);
            }
            else {
                Try(str2, idx + 1);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> rs;
        if (digits.empty())
            return rs;

        this->digits = digits;
        initLetters();
        Try("", 0);

        return combinations;
    }
};

int main()
{
    string digits = "3";
    Solution sln;
    vector<string> rs = sln.letterCombinations(digits);
    cout << rs.size() << endl;
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
