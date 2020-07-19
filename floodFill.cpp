#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void fill(vector<vector<int>>& image, int sr, int sc, int newColor, int starting)
    {
        if (image[sr][sc] == starting)
        {
            image[sr][sc] = newColor;
            if (sr >= 1)
                fill(image, sr-1, sc, newColor, starting);
            if (sr + 1 < image.size())
                fill(image, sr+1, sc, newColor, starting);
            if (sc >= 1)
                fill(image, sr, sc-1, newColor, starting);
            if (sc + 1 < image[0].size())
                fill(image, sr, sc+1, newColor, starting);
            
        }
    }
    
    // alternatively:
//     void fill(vector<vector<int>>& image, int sr, int sc, int newColor, int starting)
//     {
//         if (sr >= image.size() || sr < 0 || sc >= image[0].size() || sc < 0)
//             return;

//         if (image[sr][sc] == starting)
//             image[sr][sc] = newColor;
//             fill(image, sr-1, sc, newColor, starting);
//             fill(image, sr+1, sc, newColor, starting);
//             fill(image, sr, sc-1, newColor, starting);
//             fill(image, sr, sc+1, newColor, starting);
            
//     }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int startingColor = image[sr][sc];
        if (startingColor != newColor)
            fill(image, sr, sc, newColor, startingColor);
        return image;
    }
};

int main() {

    return 0;
}