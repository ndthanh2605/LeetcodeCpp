// WordSearch_79.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int drC[4] = { 0, 0, -1, 1 };
    int drR[4] = { -1, 1, 0, 0 };

    int rows, cols;
    bool found = false;
    vector<vector<bool>> visited;

    void Try(vector<vector<char>>& board, string word, int idx, int r, int c) {
        if (found)
            return;

        visited[r][c] = true;
        char ch = word[idx];
        cout << " > at pos " << r << "," << c << ", next char " << ch << endl;
        for (int i = 0; i < 4; i++)
        {
            int nextR = r + drR[i];
            int nextC = c + drC[i];
            if (nextR < 0 || nextR >= rows || nextC < 0 || nextC >= cols)
                continue;
            if (visited[nextR][nextC])
                continue;
            if (board[nextR][nextC] == ch) {
                if (idx == word.length() - 1) {
                    found = true;
                    return;
                }
                Try(board, word, idx + 1, nextR, nextC);
            }
        }
        visited[r][c] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())
            return false;
        if (board[0].empty())
            return 0;
        if (word.empty())
            return true;

        rows = board.size();
        cols = board[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == word[0]) {
                    Try(board, word, 1, i, j);
                    if (found)
                        return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> board = {
        //{'A', 'B', 'C', 'E'},
        //{'S', 'F', 'C', 'F'},
        //{'A', 'D', 'E', 'E'} };
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'}, 
        {'A', 'D', 'E', 'E'} };
    Solution sln;
    cout << sln.exist(board, "ABCB") << endl;

    return 0;
}
