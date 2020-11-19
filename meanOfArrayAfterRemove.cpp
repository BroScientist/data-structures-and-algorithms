class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int n = arr.size(), trimSize = n / 20;
        double sum = 0;
        for (int i = trimSize; i < n - trimSize; i++)
            sum += arr[i];
        return sum / (n - 2 * trimSize);
        
    }
};