class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // it doesn't get slower than this...
        vector<vector<string>> res;
        vector<string> prev = products, curr;

        for (int i = 0; i < searchWord.size(); i++)
        {
            for (string& p : prev)
            {
                if (i < p.size() && p[i] == searchWord[i])
                    curr.push_back(p);
            }
            
            // if curr is empty, it means there are no more matches and we simply insert {} until the end and return
            if (curr.size() == 0)
            {
                for (int j = i; j < searchWord.size(); j++)
                    res.push_back(curr);
                return res;
            }
            
            // sort and insert into the new iteration
            sort(begin(curr), end(curr));
            vector<string> tmp;
            for (int i = 0; i < 3; i++)
            {
                if (i == curr.size())
                    break;
                tmp.push_back(curr[i]);
            }
            res.push_back(tmp);
            prev = curr;
            curr.clear();
        }

        return res;
    }
};