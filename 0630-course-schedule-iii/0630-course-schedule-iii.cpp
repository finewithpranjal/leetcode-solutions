class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
       sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
       return a[1] < b[1];
});
        int coursetaken = 0;
        int duration = 0;
        int deadline = 0;
        int totalduration = 0;

        priority_queue<int> pq;
        for(int i = 0; i<courses.size(); i++) {
            duration = courses[i][0];
            deadline = courses[i][1];
            pq.push(duration);
            totalduration += duration;
            if(totalduration > deadline) {
                totalduration = totalduration - (pq.top());
                pq.pop();
            }
        }
           coursetaken = pq.size();
            return coursetaken;
    }
};