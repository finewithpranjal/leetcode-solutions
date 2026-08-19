class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };
    int distance(int& x, int& y) {
        int k = abs(x - y);
         return k; }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        // we have to find the closest elements hence we are using max pair heap
        // priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (int i = 0; i < n; i++) {
            int val = arr[i];
            int d = distance(x, val);
            pair<int, int> curr = {d, val};
            if (pq.size() < k) {
                pq.push(curr);
                continue;
            }
            pq.push(curr);
            pq.pop();
        }
        vector<int> res;
        while(!pq.empty()) {
            int i = pq.top().second;
            res.push_back(i);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};