#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        int sum = 0;
        for (int& n : A)
            if (n % 2 == 0)
                sum += n;
        for (vector<int>& query : queries)
        {
            if (A[query[1]] % 2 == 0)
                sum -= A[query[1]];
            A[query[1]] += query[0];
            if (A[query[1]] % 2 == 0)
                sum += A[query[1]];
            res.push_back(sum);
        }
        return res;
    }
};

int main() {

    return 0;
}