class Solution {
public:
    struct cmp{
       bool operator()(pair<int, int>&a, pair<int, int>&b) {
        if(a.first != b.first) {
            return a.first < b.first;
        }
            return a.second < b.second;
       }
    };
    int distance(int &x, int &y) {
      return x*x + y*y;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (int i = 0; i<n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dis = distance(x,y);
            int idx = i;
            pair<int, int> curr = {dis, idx};
            if(pq.size() < k) {
                pq.push(curr);
                continue;
            }
            pq.push(curr);
            pq.pop();
        }
        vector<vector<int>>res;
        while(!pq.empty()) {
             int i = pq.top().second;
             res.push_back(points[i]);
             pq.pop();
        }
        return res;
    }
};