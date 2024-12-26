class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, pair<int, int>> mp;
        for(auto match : matches){
            mp[match[0]].first++;
            mp[match[1]].second++;
        }
        vector<vector<int>> ans(2);
        for(auto [player, res] : mp){
            if(res.second==0)
                ans[0].push_back(player);
            else if(res.second == 1)
                ans[1].push_back(player);
        }
        return ans;
    }
};