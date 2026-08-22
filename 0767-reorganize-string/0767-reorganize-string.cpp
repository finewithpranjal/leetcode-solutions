class Solution {
public:
    struct cmp {
        bool operator()(pair<int, char>& a, pair<int, char>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    }; string reorganizeString(string s) {
        int n = s.size();
        // creating a map that store the frequency of each char in string;
        unordered_map<char, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
        }
        // creating a max heap of pairs
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;

        // pushing elements from map to heap
        for (auto i : mpp) {
            int freq = i.second;
            char ch = i.first;
            pair<int, char> curr = {freq, ch};
            pq.push(curr);
        }
        string res = "";
        int step = 0;
        // pushing elements into the res
        while (!pq.empty()) {
            pair<int, char> p1 = pq.top();
            pq.pop();
            if (step == 0 or res[step - 1] != p1.second) {
                res.push_back(p1.second);
                step++;
                p1.first--;
                if (p1.first > 0) {
                    pq.push(p1);
                }
            } else {
                if (pq.empty())
                    return "";
                pair<int, char> p2 = pq.top();
                pq.pop();
                res.push_back(p2.second);
                step++;
                p2.first--;
                if (p2.first > 0) {
                    pq.push(p2);
                    
                }
                pq.push(p1);
            }
            
        }
        return res;
    }
};