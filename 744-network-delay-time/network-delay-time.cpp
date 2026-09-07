class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Create adjacency list
        // adj[u] = {v, weight}
        vector<vector<pair<int,int>>> adj(n + 1);

        for(int i = 0; i < times.size(); i++) {

            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v, wt});
        }


        // distance from source k
        vector<int> dist(n + 1, INT_MAX);

        // Min heap
        // {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;


        // Source distance = 0
        dist[k] = 0;

        pq.push({0, k});


        while(!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;

            pq.pop();


            // Check all neighbours
            for(int i = 0; i < adj[node].size(); i++) {

                int neigh = adj[node][i].first;
                int wt = adj[node][i].second;

                // Relaxation
                if(d + wt < dist[neigh]) {

                    dist[neigh] = d + wt;

                    pq.push({dist[neigh], neigh});
                }
            }
        }


        // Find maximum shortest distance
        int ans = 0;

        for(int i = 1; i <= n; i++) {

            if(dist[i] == INT_MAX) {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};