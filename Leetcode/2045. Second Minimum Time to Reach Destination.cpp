class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<vector<int>> times(n + 1);

        queue<pair<int,int>> q;
        q.push({1, 0});
        times[1].push_back(0);

        vector<int> reached;

        while (!q.empty()) {
            auto [u, t] = q.front(); q.pop();

            for (int v : adj[u]) {
                int depart = t;
                if ((depart / change) % 2 == 1) {
                    depart = (depart / change + 1) * change;
                }
                int arrive = depart + time;

                if ((int)times[v].size() < 2 && 
                    (times[v].empty() || times[v].back() != arrive)) 
                {
                    times[v].push_back(arrive);
                    q.push({v, arrive});

                    if (v == n) {
                        reached.push_back(arrive);
                        if (reached.size() == 2) {
                            sort(reached.begin(), reached.end());
                            return reached[1];
                        }
                    }
                }
            }
        }
        return -1; 
    }
};
