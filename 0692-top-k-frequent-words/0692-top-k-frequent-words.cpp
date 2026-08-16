class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first != b.first)
                return a.first > b.first;

            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
       
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        unordered_map<string, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[words[i]]++;
        }
        for (auto i : mpp) {
            string word = i.first;
            int freq = i.second;
            pair<int, string>curr = {freq, word};
            if (pq.size() < k) {
                pq.push(curr);
                continue;
            }
            pq.push(curr);
            pq.pop();
        }
        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};