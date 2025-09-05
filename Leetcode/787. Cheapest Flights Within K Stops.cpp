class Solution {
public:
    // Helper BFS function
    int bfs(int n, vector<vector<pair<int,int>>>& adj, int src, int dst, int k) {
        queue<tuple<int,int,int>> q; // (city, cost, stops)
        q.push({src, 0, 0});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!q.empty()) {
            auto [city, cost, stops] = q.front();
            q.pop();

            if (stops > k) continue; // exceeded allowed stops

            for (auto &[next, price] : adj[city]) {
                int newCost = cost + price;
                if (newCost < dist[next]) {
                    dist[next] = newCost;
                    q.push({next, newCost, stops + 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]}); // (destination, price)
        }

        // Step 2: Run BFS
        return bfs(n, adj, src, dst, k);
    }
};
