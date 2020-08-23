class GraphNode
{
public:
    int indegree = 0;
    list<int> outNodes;
};

class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0)
            return true;
        // course -> list of next courses
        unordered_map<int, GraphNode> graph;
        
        // relation[1] is the prerequisite course, while relation[0] is the one that depends on it
        // add relation[0] to relation[1]'s outnodes, and increment the indegree of relation[0]
        for (vector<int>& relation : prerequisites)
        {
            graph[relation[1]].outNodes.push_back(relation[0]);
            graph[relation[0]].indegree++;
        }
        
        // start by finding all courses with no prerequisites
        int total = prerequisites.size();
        list<int> noReqCourses;
        for (auto& [course, node]: graph)
        {
            if (node.indegree == 0)
                noReqCourses.push_back(course);
        }
        
        int removedEdges = 0;
        while (noReqCourses.size() > 0)
        {
            int course = noReqCourses.back();
            noReqCourses.pop_back();
            for (int nextCourse : graph[course].outNodes)
            {
                graph[nextCourse].indegree--;
                removedEdges++;
                if (graph[nextCourse].indegree == 0)
                    noReqCourses.push_back(nextCourse);
            }
        }

        return removedEdges != total ? false : true;
    }
};