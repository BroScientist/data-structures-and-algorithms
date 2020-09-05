class SparseVector {
public:
    unordered_map<int, int> map;  // index to value
    SparseVector(vector<int> &nums) 
    {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0)
                map[i] = nums[i];
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) 
    {
        unordered_map<int, int> map2 = vec.map;
        int product = 0;
        for (auto& [index, value] : map2)
        {
            if (map.find(index) != map.end())
                product += map2[index] * map[index];
        }
        return product;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);