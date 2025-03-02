
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if (deck.size() <= 1)
            return deck;

        sort(deck.rbegin(), deck.rend());

        int n = deck.size();
        queue<int> q;
        q.push(deck[0]);
        for (int i = 1; i < n - 1; i++) {
            int first = q.front();
            q.pop();
            //cout << " > pop " << first << endl;
            q.push(deck[i]);
            //cout << " > push " << deck[i] << endl;
            q.push(first);
            //cout << " > push " << first << endl;
        }
        q.push(deck[n - 1]);

        vector<int> rs(n);
        for (int i = n - 1; i >= 0; i--) {
            rs[i] = q.front();
            q.pop();
        }
        for (auto& i : rs) {
            cout << " " << i;
        }
        cout << endl;
        return rs;
    }
};

int main()
{
    Solution sln;
    vector<int> deck = { 17,13,11,2,3,5,7 };
    cout << sln.deckRevealedIncreasing(deck).size() << endl;

    return 0;
}
