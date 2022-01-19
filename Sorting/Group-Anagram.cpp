vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int n = strs.size();
    vector<vector<string>> res;
    if (n <= 1)
    {
        res.push_back(strs);
        return res;
    }
    vector<string> s = strs;
    for (int i = 0; i < n; i++)
    {
        sort(s[i].begin(), s[i].end());
    }

    for (int i = 0; i < n; i++)
    {
        vector<string> v;
        string val = s[i];
        if (val != "-1")
        {
            int j = 0;
            while (j < n)
            {
                if (s[j] == val)
                {
                    v.push_back(strs[j]);
                    s[j] = "-1";
                }
                j++;
            }
        }
        if (v.size() > 0)
            res.push_back(v);
    }
    return res;
}