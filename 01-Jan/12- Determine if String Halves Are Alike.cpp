class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool halvesAreAlike(string s) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int half = s.size()/2;
        int cnt_a = 0, cnt_b = 0;
        for(int i = 0; i < half; i++)
            cnt_a += vowels.count(s[i]);
        for(int i = half; i < s.size(); i++)
            cnt_b += vowels.count(s[i]);
        return cnt_a == cnt_b;
    }
};