class Solution {
private:
    // Pass visited and adjList by reference to avoid copying
    void dfs(int node, const vector<vector<int>>& adjList, vector<int>& visited) {
        visited[node] = 1;
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        // Use a vector of vectors for the adjacency list
        vector<vector<int>> adjList(V);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Since it's an adjacency matrix, we only need to check isConnected[i][j]
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        // Initialize vector with size V, all set to 0
        vector<int> visited(V, 0);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adjList, visited);
            }
        }

        return count;
    }
};