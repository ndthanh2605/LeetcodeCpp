// TakeKofCharsFromLeftRight_2516.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    string s;
    int k;
    vector<int> aIndexes;
    vector<int> bIndexes;
    vector<int> cIndexes;
    vector<int> steps;
    int iA = 0, iB = 0, iC = 0;
    int minCost, tmpCost = 0;
    int pL, pR;

    int checkLeft() {       // 0 : not change, 1 : add 'a', 2 : add 'b', 3 : add 'c'
        if (s[pL] == 'a') {
            aIndexes[iA] = pL;
            iA++;
            return 1;
        }
        if (s[pL] == 'b') {
            bIndexes[iB] = pL;
            iB++;
            return 2;
        }
        if (s[pL] == 'c') {
            cIndexes[iC] = pL;
            iC++;
            return 3;
        }
        return -1;
    }

    int checkRight() {       // 0 : not change, 1 : add 'a', 2 : add 'b', 3 : add 'c'
        if (s[pR] == 'a') {
            aIndexes[iA] = pR;
            iA++;
            return 1;
        }
        if (s[pR] == 'b') {
            bIndexes[iB] = pR;
            iB++;
            return 2;
        }
        if (s[pR] == 'c') {
            cIndexes[iC] = pR;
            iC++;
            return 3;
        }
        return -1;
    }

    int takeCharacters(string s, int k) {
        if (k == 0)
            return 0;

        int l = s.length();
        if (l < k * 3)
            return -1;

        this->s = s;
        this->k = k;
        aIndexes = vector<int>(l, -1);
        bIndexes = vector<int>(l, -1);
        cIndexes = vector<int>(l, -1);
        steps = vector<int>(l, -1);
        minCost = l + 1;

        pL = 0, pR = l - 1;

        // move pL & pR toward center until satisfied
        bool found = false;
        while (pL <= pR)
        {
            checkLeft();
            if (iA >= k && iB >= k && iC >= k) {
                found = true;
                if (pR == pL)
                    pR++;
                break;
            }
            pL++;
            checkRight();
            if (iA >= k && iB >= k && iC >= k) {
                found = true;
                if (pR == pL)
                    pL--;
                break;
            }
            pR--;
        }
        if (!found)
            return -1;

        // expanding pL & pR outside as long as satisfied
        while (pL >= 0)
        {
            char c = s[pL];
            if (c == 'a') {
                auto itr = find(aIndexes.begin(), aIndexes.begin() + iA, pL);
                if (itr != aIndexes.end() && itr - aIndexes.begin() < k)
                    break;
            }
            else if (c == 'b') {
                auto itr = find(bIndexes.begin(), bIndexes.begin() + iB, pL);
                if (itr != bIndexes.end() && itr - bIndexes.begin() < k)
                    break;
            }
            else if (c == 'c') {
                auto itr = find(cIndexes.begin(), cIndexes.begin() + iC, pL);
                if (itr != cIndexes.end() && itr - cIndexes.begin() < k)
                    break;
            }
            pL--;
        }
        while (pR < l)
        {
            char c = s[pR];
            if (c == 'a') {
                auto itr = find(aIndexes.begin(), aIndexes.begin() + iA, pR);
                if (itr != aIndexes.end() && itr - aIndexes.begin() < k)
                    break;
            }
            else if (c == 'b') {
                auto itr = find(bIndexes.begin(), bIndexes.begin() + iB, pR);
                int d = itr - bIndexes.begin();
                if (itr != bIndexes.end() && itr - bIndexes.begin() < k)
                    break;
            }
            else if (c == 'c') {
                auto itr = find(cIndexes.begin(), cIndexes.begin() + iC, pR);
                if (itr != cIndexes.end() && itr - cIndexes.begin() < k)
                    break;
            }
            pR++;
        }

        return pL + 1 + l - pR;
    }
};


int main()
{
    string s = "acba";
    Solution sln;
    cout << sln.takeCharacters(s, 1) << endl;

    return 0;
}
