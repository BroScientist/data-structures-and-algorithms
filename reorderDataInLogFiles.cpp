class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // letter-logs before digit-log
        // order letter-logs in order of string, use id in case of tie
        // preserve the order of digit logs (so attach them to the end)
        vector<string> letterLogs, digitLogs;
        for (string& log : logs)
        {
            if (isalpha(log.back()))
                letterLogs.push_back(log);
            else
                digitLogs.push_back(log);
        }
        
        sort(begin(letterLogs), end(letterLogs), [] (string a, string b) 
             {
                 // parse the id and the word part
                 string id1 = "", id2 = "", s1 = "", s2 = "";
                 // find the first space
                 int index = 0;
                 for (int i = 0; i < a.size(); i++)
                 {
                     if (a[i] == ' ')
                     {
                         index = i;
                         break;
                     }
                 }
                 for (int i = 0; i < index; i++)
                     if (isdigit(a[i]))
                         id1 += a[i];
                 
                 for (int i = index + 1; i < a.size(); i++)
                     s1 += a[i];
                 
                 for (int i = 0; i < b.size(); i++)
                 {
                     if (b[i] == ' ')
                     {
                         index = i;
                         break;
                     }
                 }
                 for (int i = 0; i < index; i++)
                     if (isdigit(b[i]))
                         id2 += b[i];
                 for (int i = index + 1; i < b.size(); i++)
                     s2 += b[i];
                 return s1 == s2 ? stoi(id1) < stoi(id2) : s1 < s2;
             });
        
        vector<string> res;
        for (auto& v : letterLogs)
            res.push_back(v);
        for (auto& v : digitLogs)
            res.push_back(v);
        return res;
    }
};