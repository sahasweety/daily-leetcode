class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> minH;

        vector<bool> visited(n, false);

        minH.push({0, 0});

        int ans = 0;

        while (!minH.empty()) {

            int cost = minH.top().first;
            int node = minH.top().second;

            minH.pop();

            if (visited[node]) {
                continue;
            }

            visited[node] = true;
            ans += cost;

            for (int i = 0; i < n; i++) {

                if (!visited[i]) {

                    int newCost =
                        abs(points[node][0] - points[i][0]) +
                        abs(points[node][1] - points[i][1]);

                    minH.push({newCost, i});
                }
            }
        }

        return ans;
    }
};