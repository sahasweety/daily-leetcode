class Solution {
public:
    std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
        // Step 1: Build the adjacency list for the directed graph
        std::vector<std::vector<int>> graph(n);
        for (const auto& inv : invocations) {
            graph[inv[0]].push_back(inv[1]);
        }
        
        // Step 2: Find all suspicious methods using DFS starting from k
        std::vector<bool> suspicious(n, false);
        std::stack<int> stack;
        
        stack.push(k);
        suspicious[k] = true;
        
        while (!stack.empty()) {
            int curr = stack.top();
            stack.pop();
            
            for (int neighbor : graph[curr]) {
                if (!suspicious[neighbor]) {
                    suspicious[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }
        
        // Step 3: Check if any non-suspicious method invokes any suspicious method
        for (const auto& inv : invocations) {
            int u = inv[0], v = inv[1];
            if (!suspicious[u] && suspicious[v]) {
                // External dependency found! We cannot remove any suspicious methods.
                std::vector<int> result(n);
                for (int i = 0; i < n; ++i) {
                    result[i] = i;
                }
                return result;
            }
        }
        
        // Step 4: Otherwise, collect all non-suspicious methods to keep
        std::vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!suspicious[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};