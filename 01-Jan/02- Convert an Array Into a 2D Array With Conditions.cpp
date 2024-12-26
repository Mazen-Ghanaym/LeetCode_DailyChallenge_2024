class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq(205); // each element frequency
        int max_freq = 0; // number of array = maximum number of frequencies for a single number

        // iterate through the nums array to record each occurence of a number
        for(auto &it: nums){
            freq[it]++;
            max_freq = max(max_freq, freq[it]);
        }
        vector<vector<int>> vc(max_freq);
        for(int i = 1; i <= 200; i++){
            for(int j = 0; j < freq[i]; j++){
                vc[j].push_back(i);
            }
        }
        return vc;
    }
};