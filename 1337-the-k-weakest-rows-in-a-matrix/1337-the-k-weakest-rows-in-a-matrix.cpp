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
    int count_ones(vector<vector<int>>& mat, int i) {
        int count = 0;
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 1)
                count++;
        }
        return count;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        for (int i = 0; i < m; i++) {

            int no_of_ones = count_ones(mat, i);
            pair<int, int> curr = {no_of_ones, i};
            if (pq.size() < k) {
                pq.push(curr);
                continue;
            }

            pq.push(curr);
            pq.pop();
        }

        vector<int> res;
        while (!pq.empty()) {
            int idx = pq.top().second;
            res.push_back(idx);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};