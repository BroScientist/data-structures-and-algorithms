#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
public:
    vector<int> rows, cols;
    int diag, antiDiag, size;
    TicTacToe(int n) {
        rows = vector<int>(n);
        cols = vector<int>(n);
        diag = 0;
        antiDiag = 0;
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int x = row, y = col;
        if (player == 1)
        {
            rows[x]++;
            cols[y]++;
            if (rows[x] == size || cols[y] == size)
                return 1;
            if (x == y)
            {
                diag++;
                if (size % 2 != 0 && x == size / 2 && y == size / 2)
                    antiDiag++;
            }
            if (x != y && x + y == size - 1)
                antiDiag++;
            if (diag == size || antiDiag == size)
                return 1;
        }
        else
        {
            rows[x]--;
            cols[y]--;
            if (rows[x] == -size || cols[y] == -size)
                return 2;
            if (x == y)
            {
                diag--;
                if (size % 2 != 0 && x == size / 2 && y == size / 2)
                    antiDiag--;
            }
            if (x != y && x + y == size - 1)
                antiDiag--;
            if (diag == -size || antiDiag == -size)
                return 2;                
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */