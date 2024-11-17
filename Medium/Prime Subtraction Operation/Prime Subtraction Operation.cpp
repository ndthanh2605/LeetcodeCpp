// Prime Subtraction Operation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> primes = { 2, 3, 5, 7 };
    vector<int> result;
    
    bool checkPrime(int n) {
        for (auto& i : primes)
        {
            if (n < i)
                return false;
            if (n == i)
                return true;
            if (n % i == 0) {
                return false;
            }
        }
        // n is greater than all cached primes
        // continue checking from (last prime + 1) to sqrt(n)
        for (int i = primes[primes.size() - 1] + 2; i <= sqrt(n); i += 2)
        {
            if (n % i == 0)
                return false;
        }
        primes.push_back(n);
        return true;
    }

    void createPrimesBelow(int n) {
        if (n < 9)
            return;
        for (int i = 9; i < n; i += 2)
        {
            checkPrime(i);
        }
    }

    int found = 0;     // -1: false, 1: true
    // try subtracting a prime from the number at idx position
    void Try(int idx) {
        if (found)
            return;

        int next = result[idx + 1];
        int cur = result[idx];
        //cout << " > Try idx " << idx << ", next " << next << ", value " << cur << endl;

        if (cur < next) {
            // do not need to subtract
            if (idx == 0) {
                found = 1;
                return;
            }
            Try(idx - 1);
        }
        else {
            // must subtract to make 'cur' < 'next'
            bool canSubstract = false;
            if (cur > primes[primes.size() - 1]) {
                createPrimesBelow(cur);
            }

            for (auto& p : primes)
            {
                if (p >= cur)
                    continue;

                // try a prime
                int tmp = cur - p;
                if (tmp >= next)
                    continue;
                
                canSubstract = true;
                result[idx] = tmp;
                if (idx == 0) {
                    found = 1;
                    return;
                }
                Try(idx - 1);

                // backtrack
                result[idx] = cur;
            }
            if (!canSubstract) {
                found = -1;
                return;
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        //createPrimesBelow(*max_element(nums.begin(), nums.end()));
        
        result = vector<int>(nums);
        // backtrack from the item next to the last
        Try(nums.size() - 2);

        return found == 1;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = { 4,9,6,10 };
    //vector<int> nums = { 6,8,11,12 };
    vector<int> nums = { 18,4,16,8,4 };
    
    cout << sln.primeSubOperation(nums) << endl;

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
