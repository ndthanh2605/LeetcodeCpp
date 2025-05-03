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
        // dp(idx, state)
        // if state is NOT prime => dp(idx + 1, state + s[idx])
        // else => plus dp(idx + 1, s[idx])
        // base case : idx == n, return 1 if state is prime, else return 0

        map<pair<int, string>, int> mem;
        vector<vector<string>> ans;
        function<int(int, string, vector<string>)> dp = [&](int idx, string state, vector<string> splits) -> int
            {
                // check valid
                if (!valid(state))
                    return 0;

                cout << "check : " << idx << " " << state << " " << splits.size() << endl;
                // check prime
                bool p = primes[stoi(state)];
                if (idx == n) {
                    if (p) {
                        splits.push_back(state);
                        ans.push_back(splits);
                        cout << " > end case : " << state << endl;
                    }
                    return p ? 1 : 0;
                }
        
                pair<int, string> key = { idx, state };
                if (mem.count(key))
                    return mem[key];

                string _state = state + s[idx];
                int rs = dp(idx + 1, _state, splits);
                if (p) {
                    splits.push_back(state);
                    int tmp = dp(idx + 1, s.substr(idx, 1), splits);
                    rs += tmp;
                }
                return mem[key] = rs;
            };

        int rs = dp(1, s.substr(0, 1), {});
        for (auto& splits : ans) {
            for (auto& s : splits)
                cout << s << " ";
            cout << endl;
        }
        cout << endl;

        return rs;
    }
};

int main()
{
    Solution sln;
    //cout << sln.splitPrimes("11373") << endl;
    //cout << sln.splitPrimes("011") << endl;
    //cout << sln.splitPrimes("1234") << endl;
    //cout << sln.splitPrimes("113") << endl;
    cout << sln.splitPrimes("2357") << endl;

    return 0;
}
