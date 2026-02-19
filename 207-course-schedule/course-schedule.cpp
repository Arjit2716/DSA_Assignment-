class Solution {
public:

    bool topologicalSortCheck(unordered_map<int, vector<int>>& adj,
                              int n,
                              vector<int>& indegree) {
        
        queue<int> q;
        int count = 0;

        // Push all nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;

            for (int v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return count == n;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for (auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            // b → a
            adj[b].push_back(a);
            indegree[a]++;
        }

        return topologicalSortCheck(adj, numCourses, indegree);
    }
};