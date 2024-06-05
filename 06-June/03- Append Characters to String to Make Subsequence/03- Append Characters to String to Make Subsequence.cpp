class Solution {
public:
    int appendCharacters(string s, string t) {
        int pt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == t[pt])
                pt++;
            if(pt == t.size())break;
        }
        return t.size() - pt;
    }
};