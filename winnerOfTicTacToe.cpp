#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> row(3, 0), col(3, 0);
        int diag = 0, antiDiag = 0;
        bool A = true;
        int steps = 0;
        for (vector<int>& move : moves)
        {
            int x = move[0], y = move[1];
            if (A)
            {
                row[x]++;
                col[y]++;
                if (row[x] == 3 || col[y] == 3)
                    return "A";
                if (x == y)
                {
                    diag++;
                    if (x == 1 && y == 1)
                        antiDiag++;
                }
                if ((x == 0 && y == 2) || (x == 2 && y == 0))
                    antiDiag++;
                if (diag == 3 || antiDiag == 3)
                    return "A";
            }
            else
            {
                row[x]--;
                col[y]--;
                if (row[x] == -3 || col[y] == -3)
                    return "B";
                if (x == y)
                {
                    diag--;
                    if (x == 1 && y == 1)
                        antiDiag--;
                }
                if ((x == 0 && y == 2) || (x == 2 && y == 0))
                    antiDiag--;
                if (diag == -3 || antiDiag == -3)
                    return "B";                
            }
            A = !A;
            steps++;
            if (steps >= 9)
                return "Draw";
        }
        return "Pending";
    }
};