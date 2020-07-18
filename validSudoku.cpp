#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for every row, column and 3x3 square, use a hashtable to detect duplicate elements
        // simply add the current number to the unordered map and if find() != map.end() return false
        unordered_map<char, int> hashtable;
        // for every row
        for (int row = 0; row < board.size(); row++)
        {
            hashtable.clear();
            for (int col = 0; col < board[0].size(); col++)
            {
                char c = board[row][col];
                if (hashtable.find(c) != hashtable.end())
                    return false;
                if (c != '.')
                    hashtable[c]++;
            }
        }
        // for every column
        for (int col = 0; col < board[0].size(); col++)
        {
            hashtable.clear();
            for (int row = 0; row < board.size(); row++)
            {
                char c = board[row][col];
                if (hashtable.find(c) != hashtable.end())
                    return false;
                if (c != '.')
                    hashtable[c]++;
            }
        }   
        
        // for every 3x3 square (no overlaps)
        for (int row = 0; row < board.size(); row += 3)
        {
            for (int col = 0; col < board[0].size(); col += 3)
            {
                hashtable.clear();
                for (int i = row; i < row + 3; i++)
                {
                    for (int j = col; j < col + 3; j++)
                    {
                        char c = board[i][j];
                        if (hashtable.find(c) != hashtable.end())
                            return false;
                        if (c != '.')
                            hashtable[c]++;
                    }
                }
            }
        }
        
        return true;
    }
};

int main() {

    return 0;
}