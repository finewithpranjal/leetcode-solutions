class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Creating an adjecency list:
        int src = k;
        src--;
        vector<vector<pair<int, int>>> list(n);
        for (int i = 0; i < times.size(); i++) {
            int s = times[i][0];
            int d = times[i][1];
            int t = times[i][2];

            list[s - 1].push_back({d - 1, t});
        }
        // Creating a min heap of pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;

            if (d > dist[node])
                continue;

            for (int j = 0; j < list[node].size(); j++) {
                int it = list[node][j].first;
                int wt = list[node][j].second;

                if (wt + d < dist[it]) {
                    dist[it] = wt + d;
                    pq.push({wt + d, it});
                }
            }
        }
            int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            res = max(res, dist[i]);
        }
        if (res != INT_MAX) {
            return res;
        }
        return -1;
    }
};