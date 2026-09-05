class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {

            // If node is already colored
            if(color[i] != -1)
                continue;

            queue<int> q;

            q.push(i);
            color[i] = 0;

            while(!q.empty()) {

                int node = q.front();
                q.pop();

                for(int j = 0; j < graph[node].size(); j++) {

                    int neigh = graph[node][j];

                    // Neighbour is not colored
                    if(color[neigh] == -1) {

                        color[neigh] = 1 - color[node];

                        q.push(neigh);
                    }

                    // Neighbour has same color
                    else if(color[neigh] == color[node]) {

                        return false;
                    }
                }
            }
        }

        return true;
    }
};