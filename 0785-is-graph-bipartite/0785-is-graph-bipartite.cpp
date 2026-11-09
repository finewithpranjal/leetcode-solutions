class Solution {
public:
    bool res = true;
    void dfs(vector<vector<int>>& arr, int node, int c, vector<int> &colors) {
        colors[node] = c;
        for(int j = 0; j<arr[node].size(); j++) {
            int item = arr[node][j];
            if(colors[item] != -1 and colors[item] == c ) {
                res = false;
            }
            if(colors[item] == -1) {
                dfs(arr, item, 1-c, colors);
            }
        }
        return;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colors(n, -1);
        for(int i = 0; i<n; i++) {
            if(colors[i] == -1) {
                dfs(graph, i, 0, colors);
            }
        }
        return res;
    }
};