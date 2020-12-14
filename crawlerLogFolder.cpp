class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        if (logs[0][0] != '.')
            s.push(logs[0]);
        
        for (int i = 1; i < logs.size(); i++)
        {
            string log = logs[i];
            if (log == "../" && !s.empty())
                s.pop();
            else if (log[0] != '.')
                s.push(log);
        }
        
        return s.size();
    }
};