class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int& n : nums)
            freq[n]++;
        sort(begin(nums), end(nums), [&freq] (int a, int b) 
             {
                int freqA = freq[a]; 
                int freqB = freq[b]; 
                return freqA == freqB ? a > b : freqA < freqB;
             });
        return nums;
    }
};