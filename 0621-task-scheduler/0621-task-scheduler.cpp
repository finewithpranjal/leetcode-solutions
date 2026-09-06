class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int s = tasks.size();
        // map for storing frequency and char
        unordered_map<char, int> mpp;
        // map for stroing element's next seat
        unordered_map<char, int> ns;

        // inserting in map

        for (int i = 0; i < s; i++) {
            mpp[tasks[i]]++;
            ns[tasks[i]] =
                1; // means every element can be seated on seat 1 initially
        }

        // creating a max heap
        priority_queue<pair<int, char>> pq;

        // storing in the heap
        for (auto i : mpp) {
            pq.push({i.second, i.first});
        }

        int seat = 1;
        while (!pq.empty()) {
            // for storing temp elements
            vector<pair<int, char>> temp;

            while (!pq.empty()) {

                pair<int, char> p = pq.top();
                pq.pop();
                int freq = p.first;
                char child = p.second;

                if (ns[child] <= seat) { // he can seat
                    freq--;
                    if (freq > 0) {
                        pq.push({freq, child});
                        ns[child] = seat + n + 1;
                    }
                    break;
                }
                // cannot seat
                temp.push_back(p);
            }
            for(auto p : temp) {
                pq.push(p);
            }
            seat++;
        }
        return seat -1;
    }
};