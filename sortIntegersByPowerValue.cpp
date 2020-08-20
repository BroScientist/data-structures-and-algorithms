class Solution {
public:
    int getKth(int lo, int hi, int k) {
        unordered_map<int,int> cache;
        vector<int> nums;
        for (int i = lo; i <= hi; i++)
            nums.push_back(i);
        sort(begin(nums), end(nums), [&cache] (int& a, int& b)
             {
                 int power1 = 0, power2 = 0;
                 int num1 = a, num2 = b;
                 if (cache.find(num1) == cache.end())
                 {
                     while (num1 != 1)
                     {
                         if (num1 % 2 == 0)
                             num1 = num1 / 2;
                         else
                             num1 = 3 * num1 + 1;
                         power1++;
                     }
                     cache[num1] = power1;
                 }
                 else
                     power1 = cache[num1];
                
                 if (cache.find(num2) == cache.end())
                 {
                     while (num2 != 1)
                     {
                         if (num2 % 2 == 0)
                             num2 = num2 / 2;
                         else
                             num2 = 3 * num2 + 1;
                         power2++;
                     }
                     cache[num2] = power2;
                 }
                 else
                     power2 = cache[num2];
                 
                 return power1 == power2 ? a < b : power1 < power2;
             });
        return nums[k - 1];
    }
};