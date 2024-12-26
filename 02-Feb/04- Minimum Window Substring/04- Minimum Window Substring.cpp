class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool check(vector<int> &freqls, vector<int> &freqlt, vector<int> &frequs, vector<int> &frequt)
    {
        for (int i = 0; i < 26; i++)
        {
            if (freqls[i] < freqlt[i])
                return false;
            if (frequs[i] < frequt[i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        int mnw = 0;
        deque<char> mnws;
        vector<int> freqls(26), freqlt(26), frequs(26), frequt(26);
        for (auto c : t)
        {
            if (isupper(c))
                frequt[c - 'A']++;
            else
                freqlt[c - 'a']++;
        }
        int i = 0;
        int n = s.size();
        deque<char> cur;
        while (i < n && !check(freqls, freqlt, frequs, frequt))
        {
            if (islower(s[i]))
                freqls[s[i] - 'a']++;
            else
                frequs[s[i] - 'A']++;
            cur.push_back(s[i]);
            i++;
        }
        mnws = cur;
        mnw = i - 1;
        int st = 0, end = i;
        while (end < n && st <= end)
        {
            cout << st << " " << end << " " << mnw << "\n";
            if (check(freqls, freqlt, frequs, frequt))
            {
                if (end - st - 1 < mnw)
                {
                    mnw = end - st;
                    mnws = cur;
                }
                if (isupper(s[st]))
                    frequs[s[st++] - 'A']--;
                else
                    freqls[s[st++] - 'a']--;
                cur.pop_front();
            }
            if (!check(freqls, freqlt, frequs, frequt))
            {
                if (isupper(s[end]))
                    frequs[s[end] - 'A']++;
                else
                    freqls[s[end] - 'a']++;
                cur.push_back(s[end]);
                end++;
            }
        }
        while (st < n && check(freqls, freqlt, frequs, frequt))
        {
            if (end - st - 1 < mnw)
            {
                mnw = end - st - 1;
                mnws = cur;
            }
            if (isupper(s[st]))
                frequs[s[st] - 'A']--;
            else
                freqls[s[st] - 'a']--;
            cur.pop_front();
            st++;
        }
        string ans = "";
        vector<int> rescheckl(26), reschecku(26);
        for (auto c : mnws)
        {
            if (isupper(c))
                reschecku[c - 'A']++;
            else
                rescheckl[c - 'a']++;
            ans += c;
        }
        return (check(rescheckl, freqlt, reschecku, frequt) ? ans : "");
    }
};