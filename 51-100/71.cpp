class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> files;
        int n = path.size();
        string file;
        for (auto i : path)
        {
            if (i == '/')
            {
                if (file.size() > 0)
                {
                    files.push_back(file);
                }
                file = "";
            }
            else
            {
                file += i;
            }
        }
        if (file.size() > 0)
        {
            files.push_back(file);
        }

        vector<string> s;
        for (auto i : files)
        {
            if (i == ".")
                continue;
            else if (i == "..")
            {
                if (!s.empty())
                    s.pop_back();
            }
            else
            {
                s.push_back(i);
            }
        }

        string ans;
        if (s.empty())
        {
            ans = "/";
        }
        else
        {
            for (auto &i : s)
            {
                ans += "/" + i;
            }
        }

        return ans;
    }
};