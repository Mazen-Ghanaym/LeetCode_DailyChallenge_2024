class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string frequencySort(string s)
    {
        vector<int> frequ(26), freql(26), digits(10);
        for (auto c : s)
            if (isdigit(c))
                digits[c - '0']++;
            else if (isupper(c))
                frequ[c - 'A']++;
            else
                freql[c - 'a']++;
        vector<pair<int, char>> vc;
        for (int i = 0; i < 26; i++)
        {
            vc.push_back({freql[i], char(i + 'a')});
            vc.push_back({frequ[i], char(i + 'A')});
            if (i < 10)
                vc.push_back({digits[i], char(i + '0')});
        }
        sort(vc.rbegin(), vc.rend());
        string ans = "";
        for (auto [cnt, c] : vc)
        {
            while (cnt--)
                ans += c;
        }
        return ans;
    }
};