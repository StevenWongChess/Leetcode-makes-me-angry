class Logger
{
public:
    vector<unordered_map<string, bool> > checker = vector<unordered_map<string, bool> >(10);
    int start = -10, index = 0;

    Logger()
    {
    }

    bool shouldPrintMessage(int timestamp, string message)
    {
        bool ans = true;
        for (int i = 0; i < 10; ++i)
        {
            int it = (i + index) % 10;
            if (start + i > timestamp - 10)
                if (checker[it].count(message))
                    ans = false;
        }

        int diff = timestamp - (start + 9);
        for (int i = 0; i < min(diff, 10); ++i)
        {
            checker[(index + i) % 10] = {};
        }

        if (ans)
        {
            checker[(index + diff + 9) % 10][message] = true;
            index = (index + diff) % 10;
            start = timestamp - 9;
        }
        return ans;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */