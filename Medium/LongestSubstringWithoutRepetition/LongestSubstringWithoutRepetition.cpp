// LongestSubstringWithoutRepetition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1)
            return s.length();

        unordered_map<char, int> charIdx;

        int rs = 1;
        int pL = 0, pR = 1;
        char cL = s[pL], cR;
        charIdx[cL] = pL;

        while (pR < s.length())
        {
            // check char at pR
            cR = s[pR];
            //cout << " > check R at " << pR << ", char " << cR << endl;
            if (charIdx.find(cR) != charIdx.end()) {
                if (charIdx[cR] >= pL) {

                    // it's duplicated
                    // move pL to the next pos of that idx
                    pL = charIdx[cR] + 1;
                    cL = s[pL];
                    charIdx[cR] = pR;
                    pR++;
                    //cout << " > move L to " << pL << endl;
                    continue;
                }
            }

            rs = max(rs, pR - pL + 1);
            charIdx[cR] = pR;
            pR++;
        }
        return rs;
    }
};
int main()
{
    Solution sln;
    string s = "abcabcbb";
    //string s = "tmmzuxt";
    cout << sln.lengthOfLongestSubstring(s) << endl;

    return 0;
}
