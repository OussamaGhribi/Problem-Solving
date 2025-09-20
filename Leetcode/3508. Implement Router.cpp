class Router {
    int memoryLimit;
    queue<vector<int>> q;
    unordered_set<string> seen;
    unordered_map<int, vector<int>> destToTimestamps;

    string makeKey(int s, int d, int t) {
        return to_string(s) + "#" + to_string(d) + "#" + to_string(t);
    }

public:
    Router(int limit) : memoryLimit(limit) {}
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        if (seen.count(key)) return false;

        if (q.size() == memoryLimit) {
            auto old = q.front(); q.pop();
            string oldKey = makeKey(old[0], old[1], old[2]);
            seen.erase(oldKey);
            auto &vec = destToTimestamps[old[1]];
            vec.erase(lower_bound(vec.begin(), vec.end(), old[2]));
        }

        q.push({source, destination, timestamp});
        seen.insert(key);
        destToTimestamps[destination].push_back(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};

        auto pkt = q.front(); q.pop();
        string key = makeKey(pkt[0], pkt[1], pkt[2]);
        seen.erase(key);

        auto &vec = destToTimestamps[pkt[1]];
        vec.erase(lower_bound(vec.begin(), vec.end(), pkt[2]));

        return pkt;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (!destToTimestamps.count(destination)) return 0;
        auto &vec = destToTimestamps[destination];
        auto it1 = lower_bound(vec.begin(), vec.end(), startTime);
        auto it2 = upper_bound(vec.begin(), vec.end(), endTime);
        return it2 - it1;
    }
};
