#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNeighbors(vector<vector<int>>& board, vector<int> pos)
    {
        int count = 0;
        for (int i = pos[0] - 1; i <= pos[0] + 1; i++)
        {
            for (int j = pos[1] - 1; j <= pos[1] + 1; j++)
            {
                if (i < 0 || j < 0 || i == board.size() || j == board[0].size())
                    continue;
                if (i == pos[0] && j == pos[1])
                {
                    // cout << "x";
                    continue;
                }
                if (board[i][j] == 1)
                    count++;
                // cout << board[i][j];
            }
            // cout << endl;
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> changeToOne, changeToZero;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                vector<int> pos = {i, j};
                int neighbors = countNeighbors(board, pos);
                if (board[i][j] == 1 && neighbors < 2)
                    changeToZero.push_back(pos);
                else if (board[i][j] == 1 && neighbors > 3)
                    changeToZero.push_back(pos);
                else if (board[i][j] == 0 && neighbors == 3)
                    changeToOne.push_back(pos);
            }
        }
        for (vector<int>& vec : changeToOne)
            board[vec[0]][vec[1]] = 1;
        for (vector<int>& vec : changeToZero)
            board[vec[0]][vec[1]] = 0;
    }
};

int main() {

    return 0;
}