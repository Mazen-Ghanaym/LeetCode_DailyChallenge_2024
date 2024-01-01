class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort g ascending
        sort(g.begin(), g.end());
        // sort s descending to use back and to match with g
        sort(s.rbegin(), s.rend());
        int count=0; // counter to count number cookies
        int sz = g.size();

        for(int i = 0; i < sz; i++){
            // loop until you found a suitable s[j] for g[i]
            while(!s.empty() && s.back() < g[i] ){
                s.pop_back();
            }
            // if you found suitable s that match with g pop it and increase cookies
            if(!s.empty() && s.back() >= g[i]){
                count++;
                s.pop_back();
            }
        }
        return count;
    }
};