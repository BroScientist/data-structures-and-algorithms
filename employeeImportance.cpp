#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, pair<int, vector<int>>> idToInfo;
        for (Employee* emp : employees)
            idToInfo[emp->id] = make_pair(emp->importance, emp->subordinates);
        
        queue<int> queue; // queue of ids, which can then be used to retrieve importantce & subs
        int value = idToInfo[id].first;
        for (int& empId : idToInfo[id].second)
            queue.push(empId);
        while (!queue.empty())
        {
            int count = queue.size();
            while (count != 0)
            {
                int currId = queue.front();
                queue.pop();
                value += idToInfo[currId].first;
                for (int& empId : idToInfo[currId].second)
                    queue.push(empId);
                count--;
            }
        }
        return value;
    }
};