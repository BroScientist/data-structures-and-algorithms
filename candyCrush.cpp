class Solution {
public:
    set<pair<int,int>> toCrush;
    bool stable = false;
    void crush(vector<vector<int>>& board)
    {
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                if (board[row][col] == 0)
                    continue;
                // scan down
                int rowMatch = 0, colMatch = 0;
                vector<pair<int,int>> vertical, horizontal;
                vertical.push_back(make_pair(row, col));
                horizontal.push_back(make_pair(row, col));
                
                for (int i = 1; row + i < board.size(); i++)
                {
                    if (board[row + i][col] == board[row][col])
                        rowMatch++, vertical.push_back(make_pair(row + i, col));
                    else
                        break;
                }
                for (int j = 1; col + j < board[0].size(); j++)
                {
                    if (board[row][col + j] == board[row][col])
                        colMatch++, horizontal.push_back(make_pair(row, col + j));
                    else
                        break;
                }
                if (vertical.size() >= 3)
                    for (auto& n : vertical)
                        toCrush.insert(n);
                if (horizontal.size() >= 3)
                    for (auto& n : horizontal)
                        toCrush.insert(n);
            }
            
        }
        if (toCrush.empty())
        {
            stable = true;
            return;
        }
        for (auto& index : toCrush)
            board[index.first][index.second] = 0;
        // for (int i = 0; i < board.size(); i++)
        // {
        //     for (int j = 0; j < board[0].size(); j++)
        //     {
        //         cout << board[i][j] << "\t";
        //     }
        //     cout << endl;
        // }
        toCrush.clear();
        drop(board);
        // cout << endl;
    }
    
    void drop(vector<vector<int>>& board)
    {
        for (int col = 0; col < board[0].size(); col++)
        {
            for (int row = 0; row < board.size(); row++)
            {
                if (board[row][col] == 0)
                {
                    int i = row;
                    while (i != 0)
                    {
                        swap(board[i][col], board[i - 1][col]);
                        i--;
                    }
                }
            }
        }
    }
    
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        // find each candy that should be removed, store this as an array of indices
        // implement gravity by bubbling up zeros until another zero or the top is reached
        while (!stable)
            crush(board);
        return board;
    }
};