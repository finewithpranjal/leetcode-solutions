class Solution {
public:
    // always use min heap when they asked for max, most, top or lagrer values
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first != b.first) // first element of both pairs are not equal
                return a.first > b.first;

            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();
        if (k == n)
            return nums;
        // crating a pair heap (for min min)
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        // creating a map for storing the fequencies of element
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        for (auto i : mpp) {
            int element = i.first;
            int frequency = i.second;
            pair<int, int> curr = {frequency, element};
            if (pq.size() < k){
              pq.push(curr);
              continue;
            }
            if (curr.first < pq.top().first)
                continue;
            else {
                pq.pop();
                pq.push(curr);
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};