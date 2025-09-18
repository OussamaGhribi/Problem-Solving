class TaskManager {
private:
    unordered_map<int, pair<int,int>> taskMap;
    priority_queue<pair<int,int>> pq;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskMap[taskId] = {userId, priority};
            pq.push({priority, taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int userId = taskMap[taskId].first;
        taskMap[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        taskMap.erase(taskId);
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId] = pq.top();
            pq.pop();
            if (taskMap.count(taskId) && taskMap[taskId].second == priority) {
                int userId = taskMap[taskId].first;
                taskMap.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};
