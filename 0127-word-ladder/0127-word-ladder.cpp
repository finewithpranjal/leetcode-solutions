class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        string s = beginWord;
        string e = endWord;
        int n = wordList.size();
        unordered_map<string, int>mpp;
        for(int i=0; i<n; i++) 
        {
            mpp[wordList[i]] = 1;
        }
        if(mpp.find(s) == mpp.end()) 
            mpp[s] = 1;
    
        if(mpp.find(e) == mpp.end())
            return 0;
        
        queue<pair<string, int>>q;
        q.push({s, 1});
        mpp.erase(s);

        while(!q.empty()) 
        {
            pair<string, int> p;
            p = q.front();
            q.pop();
            
            string wo = p.first;
            int val = p.second;

            if(wo == e) return val;
            
            for(int i=0; i< wo.size(); i++)
            {
                char c = wo[i];
                for(int j = 97; j<=122; j++)
                {
                    if(c==j) continue;
                    wo[i] = j;
                    if(mpp.find(wo) != mpp.end()) {
                        q.push({wo, val+1});
                        mpp.erase(wo);
                    }
                }
                wo[i] = c;
            }

        }
      
        return 0;

    }
};