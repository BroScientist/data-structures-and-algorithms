class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        int n = code.size();
        vector<int> res(n, 0);
        
        if (k == 0)
            return res;
        if (k > 0)
        {
            for (int i = 0; i < n; i++)
                for (int rep = 0; rep < k; rep++)
                    res[i] += code[(i + rep + 1) % n];    
        }
        else
        {
            k = -k;
            for (int i = 0; i < n; i++)
                for (int rep = 0; rep < k; rep++)
                {
                    int index = i - rep - 1;
                    if (index < 0)
                        index = n + index;
                    res[i] += code[index];
                }
        }
        return res;
    }
};