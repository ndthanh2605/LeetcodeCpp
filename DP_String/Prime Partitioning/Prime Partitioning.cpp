// Prime Partitioning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <numeric>
#include <string>
#include <map>

using namespace std;

class Solution {
    vector<bool> primes;

public:
    const int N = 1e6;

    void sieve() {
        primes.resize(N + 1, true);
        primes[0] = primes[1] = false;
        for (int i = 2; i * i <= N; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= N; j += i) {
                    primes[j] = false;
                }
            }
        }
    }

    bool valid(const string& state) {
        if (state.empty() || state.length() > 7)
            return false;
        if (state[0] == '0')
            return false;
        if (stoi(state) > N)
            return false;
        return true;
    }

    int splitPrimes(string s) {
        sieve();

        int n = s.length();
        // dp(idx) : try next prime by len = [1..(n - idx)]
        // base case : idx == n => 1

        vector<int> m(n + 1, -1);
        function<int(int)> dp = [&](int idx) -> int
            {
                if (idx == n)
                    return 1;
                if (s[idx] == '0')
                    return 0;

                int& rs = m[idx];
                if (rs > -1)
                    return rs;

                rs = 0;
                for (int len = 1; len < 7; len++) {
                    if (len + idx > n)
                        break;
                    if (primes[stoi(s.substr(idx, len))]) {
                        rs += dp(idx + len);
                    }
                }
                return rs;
            };
        
        int rs = dp(0);
        return rs;
    }
};

int main()
{
    Solution sln;
    cout << sln.splitPrimes("11373") << endl;
    cout << sln.splitPrimes("011") << endl;
    cout << sln.splitPrimes("1234") << endl;
    cout << sln.splitPrimes("113") << endl;
    cout << sln.splitPrimes("2357") << endl;

    return 0;
}
