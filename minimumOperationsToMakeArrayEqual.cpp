class Solution {
public:
    int minOperations(int n) {
        vector<int> nums(n);
        int sum = 0, steps = 0;
        for (int i = 0; i < n; i++)
        {
            int num = 2 * i + 1;
            sum += num;
            nums[i] = num;
        }
        int avg = sum / n;
        for (int i = 0; i < n / 2; i++)
            steps += avg - nums[i];
        return steps;
    }
};