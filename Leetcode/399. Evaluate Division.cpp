class Solution {
public:
    unordered_map<string, vector<pair<string,double>>> graph;

    double dfs(const string& src, const string& dst, unordered_set<string>& vis) {
        if (!graph.count(src) || !graph.count(dst)) return -1.0;
        if (src == dst) return 1.0;

        vis.insert(src);

        for (auto& [next, weight] : graph[src]) {
            if (vis.count(next)) continue;
            double sub = dfs(next, dst, vis);
            if (sub != -1.0) 
                return weight * sub;
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
            for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> ans;
        for (auto& q : queries) {
            unordered_set<string> vis;
            ans.push_back(dfs(q[0], q[1], vis));
        }
        return ans;
    }
};
